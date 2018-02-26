#
# ld test
#
.name "ld_test"
.comment "ld test for corewar"

# should load value of pc + 34 into r3

main:
	ld 2, r3
	zjmp %:main
