#
# fork.s
#

.name "forker"
.comment "A basic forking program"

main:
	st r1, r2
	fork %10
	zjmp %:main
