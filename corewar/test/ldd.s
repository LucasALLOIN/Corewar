#
# fork.s
#

.name "ldi"
.comment "A basic ldi program"

main:
	lld 34, r3
	zjmp %:main
