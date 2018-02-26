#
# ld test
#
.name "xor_test"
.comment "xor test for corewar"

# should load value of pc + 34 into r3

main:
	xor r1,r2,r5
	zjmp %:main
