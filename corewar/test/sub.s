#
# ld test
#
.name "sub_test"
.comment "sub test for corewar"

# should load value of pc + 34 into r3

main:
	sub r1,r2,r3
	zjmp %:main
