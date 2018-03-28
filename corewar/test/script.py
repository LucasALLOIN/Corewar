#!/bin/python3
import os

files = []
for i in os.scandir():
    if i.name[len(i.name) - 2:len(i.name)] == '.s':
        files.append(i.name)

outputs1 = []
outputs2 = []
for i in files:
    outputs1.append(i[0:len(i) - 2] + ".cor")
    outputs2.append(i[0:len(i) - 2] + "2.cor")

for i,j,k in zip(files, outputs1, outputs2):
    os.system("easm {0}".format(i))
    os.system("mv {0} {1}".format(j, k))
    os.system("../../asm/asm {0}".format(i))
    ret = os.system("diff {0} {1}".format(j, k))
    if ret:
        print("\e[31m",i, "not passing\e[0m")
