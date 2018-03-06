#
# ld test
#
.name "and_test"
.comment "and test for corewar"

# should load value of pc + 34 into r3

main:
	and r1,r2,r5
	zjmp %:main
