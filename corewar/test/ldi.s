#
# fork.s
#

.name "ldi"
.comment "A basic ldi program"

main:
	ldi 3, %4, r2
	zjmp %:main
