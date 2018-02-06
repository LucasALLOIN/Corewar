## Contribution guide

#### Commits

* Commit should be done by an author on it's own branch
* This branch should be merged, after successfully created a feature, into the main dev branch
* The main dev branch will test the feature for integration.
* When the integrations tests are done, author can merge if green, recode if red.

#### Pull Request

* This happens when someone want to "release" the actual work into master.
* master is protected from writing, so you cannot commit directly.
* At pull requests, all memebers come and see the pull request for actual revision of code.
* If they decide to not merge, the request is closed and must be recoded
* If they ALL decide to merge, the pull request is merge and the project is pushed to epitech

#### Coding style

* The epitech coding style applies here

#### Documentation

* Each merge of a feature should be fully documented on the functions you made.
* If not documented your coworkers can't read the entirety of your code asap.
* It may helps you understand what functions you can use in this projets.

#### Advices

* To build up your commit onto the latest dev branch, don't forget to do this often :
    git pull origin dev
    git rebase master <name_of_your_branch>
* To make a branch:
    git branch <name_of_your_branch>
    git checkout <name_of_your_branch>
* To merge your branch:
    git checkout dev
    git merge <name_of_your_branch>
* To fix the "unrelated histoires" issue:
    Add --allow-unrelated-histories options to git commands
