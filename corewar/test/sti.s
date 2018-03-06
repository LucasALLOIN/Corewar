#
# fork.s
#

.name "ldi"
.comment "A basic ldi program"

main:
	sti r2, %4, %5
	zjmp %:main
