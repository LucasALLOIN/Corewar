#
# fork.s
#

.name "ldi"
.comment "A basic ldi program"

main:
	lddi 3, %4, r2
	zjmp %:main
