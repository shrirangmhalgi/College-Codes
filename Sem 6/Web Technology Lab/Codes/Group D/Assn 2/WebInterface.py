from flask import Flask,request,redirect,render_template
import RPi.GPIO as IO

app=Flask(__name__)

@app.route('/')
def hello_world():
    print("hello")
    return render_template('index.html')
@app.route('/led1on',methods=['POST'])
def led1on():
    """IO.output(20,1)"""
    print("LEd on")
    return redirect('/')
@app.route('/led1off',methods=['POST'])
def led1off():
    """IO.output(20,0)"""
    print("LED off")
    return redirect('/')
if __name__=='__main__':
    IO.setmode(IO.BCM)
    IO.setup(20,IO.OUT)
    app.run()
    IO.cleanup()
    
