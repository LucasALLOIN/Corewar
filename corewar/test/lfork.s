#
# fork.s
#

.name "lforker"
.comment "A basic forking program"

main:
	lfork %10
	zjmp %:main
