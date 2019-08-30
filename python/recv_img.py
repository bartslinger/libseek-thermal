#!/usr/bin/env python3

import tkinter
from tkinter import *
from PIL import Image,ImageTk
import nanomsg

root = tkinter.Tk()
label = tkinter.Label(root)
label.pack()
tkimg = [None]

sock = nanomsg.Socket(nanomsg.SUB)
sock.connect('tcp://192.168.42.1:14313'.encode('utf-8'))
sock.set_string_option(nanomsg.SUB, nanomsg.SUB_SUBSCRIBE, ''.encode('utf-8'))


def loopCapture():
    # Receive image on socket
    img_data = sock.recv()
    print(len(img_data))
    f = open("temp.jpg", "wb")
    f.write(img_data)
    f.flush()
    f.close()

    im = Image.open("temp.jpg")

    try:
        img = ImageTk.PhotoImage(im)
        print(img.height(), img.width())
        tkimg[0] = img
        label.config(image=tkimg[0])
        root.update_idletasks()
    except:
        print("dan niet")
    root.after(20, loopCapture)
    

loopCapture()
root.mainloop()
sock.close()
