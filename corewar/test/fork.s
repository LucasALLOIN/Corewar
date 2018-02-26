#
# fork.s
#

.name "forker"
.comment "A basic forking program"

main:
	fork %10
	zjmp %:main
