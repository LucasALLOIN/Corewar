#
# st test
#
.name "st_test"
.comment "st test for corewar"

# should store the value 131496 into r2

main:
	ld 2, r3
	st r3, r2
	zjmp %:main
