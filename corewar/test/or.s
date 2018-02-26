#
# ld test
#
.name "or_test"
.comment "or test for corewar"

# should load value of pc + 34 into r3

main:
	and r1,r2,r5
	zjmp %:main
