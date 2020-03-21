import os
from flask import Flask, flash, request, redirect, url_for, render_template
from werkzeug.utils import secure_filename
from PIL import Image
import torchvision.transforms as T
import torchvision
import numpy as np


UPLOAD_FOLDER = '/photo'
ALLOWED_EXTENSIONS = {'txt', 'pdf', 'png', 'jpg', 'jpeg', 'gif'}

app = Flask(__name__)
app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER

app = Flask(__name__)
cnt = 0

def allowed_file(filename):
    return '.' in filename and            filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS


@app.route('/', methods=['GET', 'POST'])
def upload_file():
    if request.method == 'POST':
        # check if the post request has the file part
        if 'file' not in request.files:
            flash('No file part')
            return redirect(request.url)

        file = request.files['file']
        # if user does not select file, browser also
        # submit an empty part without filename
        # print(file.read())

        if file.filename == '':
            flash('No selected file')
            return redirect(request.url)

        if file and allowed_file(file.filename):
            # filename = file.filename
            # file.save(os.path.join(app.config['UPLOAD_FOLDER'], filename))
            fl = open(str(cnt) + '.' + file.filename.rsplit('.', 1)[1].lower(), 'wb+')
            fl.write(file.read())
            fl.close()


            im = Image.open(str(cnt) + ".jpg")

            a = np.array(im)
            t = T.Compose([T.ToTensor()])(im)
            c = []
            c.append(t)
            model = torchvision.models.detection.fasterrcnn_resnet50_fpn(pretrained=True)
            model.eval()
            res: [{torch.tensor}]
            res = model(c)

            humanScore: float = 0.0
            ind = -1
            for key, t in res[0].items():
                if (key == 'labels'):
                    for i in range(len(t)):
                        if (t[i] == 1):
                            ind = i
                        if (key == 'scores' and ind != -1):
                            humanScore = t[ind]

                    if (humanScore > 0.75):
                        return redirect(url_for('ok'))
                    else:
                        return redirect(url_for('no'))
        else:
            flash('Error')
            return redirect(request.url)
    return render_template('base.html')


from flask import send_from_directory

@app.route('/uploads/<filename>')
def uploaded_file(filename):
    return send_from_directory(app.config['UPLOAD_FOLDER'],
                               filename)

@app.route('/ok')
def ok():
    return render_template('ok.html')


if __name__ == '__main__':
    app.run()
