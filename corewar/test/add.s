#
# ld test
#
.name "add_test"
.comment "add test for corewar"

# should load value of pc + 34 into r3

main:
	add r1,r2,r3
	zjmp %:main
