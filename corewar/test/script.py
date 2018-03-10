import os

files = []
outputs1 = []
outputs2 = []
codes = []

for i in os.scandir():
    if i.name[len(i.name) - 2:len(i.name)] == '.s':
        files.append(i.name)

for i in files:
    outputs1.append(i[0:len(i) - 2] + '.cor')
    outputs2.append(i[0:len(i) - 2] + '2.cor')

for i,j,k in zip(files,outputs1, outputs2):
    os.system("../../bonus/binaires-champ-corewar/asm " + i)
    os.system("mv {0} {1}".format(j, k))

for i,j, k in zip(files, outputs1, outputs2):
    os.system("../../asm/asm " + i)
    if os.system("diff {0} {1}".format(j, k)):
        codes.append(i)

print("Fichiers ne passant pas")
for i in codes:
    print(i)
