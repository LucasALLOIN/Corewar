#
# fork.s
#

.name "ldi"
.comment "A basic ldi program"

main:
	lldi 3, %4, r1
	zjmp %:main
