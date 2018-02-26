#
# fork.s
#
.name "lld"
.comment "A basic ldi program"

main:
	lld 34, r3
	zjmp %:main
