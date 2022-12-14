# MyGit

Some commonly used git commands and solutions.

## Git Commands

| Command | Description |
| :--- | :--- |
| `git init` \<repo_name\> | Initialize a local repository |
| `git init -b` <branch_name> | Initialize the local directory as a Git repository with a branch name |
| `git clone` <repo_url> | Clone a repository in GitHub |
| `git clone` <repo_url> `.` | Clone a repository in GitHub without project folder |
| `git status` | Check the status of the local repository |
| `git add` \<file_name\> | Add files to the temp commit area |
| `git add -A` | Stages all changes |
| `git add .` | Stages new files and modifications, without deletions |
| `git add -u` | Stages modifications and deletions, without new files |
| `git commit -m` “message” | Commit the changed files with annotation |
| `git push` | Push the commit to the default remote repository |
| `git push --set-upstream` \<remote_name\> \<branch_name\> | Push the commit to the selected repository and set this remote and branch as the unique upstream (you can use -u instead of --set-upstream) |
| `git pull` | Pull the files from the remote repository |
| `git remote -v` | Check remote repository list |
| `git remote add` \<remote_name\> \<repo_url\> | Add a remote repository with a name |
| `git remote set-url` \<remote_name\> \<repo_url\> | Change a remote's URL |
| `touch` \<file_name\> | Create a file |
| `git branch` | Check all the branches |
| `git branch` \<branch_name\> | Create a branch with a name |
| `git checkout` \<branch_name\> | Switch to that branch |
| `git branch --set-upstream-to` \<remote_name\>`/`\<remote_branch_name\> | Set the branch's upstream (you can use -u instead of --set-upstream-to) |
| `git branch -vv` | Find out which remote branch a local branch is tracking |
| `git branch -d` \<branch_name\> | Delete a branch locally |
| `git push` \<remote_name\> `--delete` \<remote_branch_name\> | Delete branch remotely |
| `git merge` \<branch-name\> | Merge the selected branch to the current branch |
| `git rm --cached` \<file_name\> | Remove file from the index instead of deleting the real file in the local system |
| `git rm -r --cached` \<folder_name\> | Remove folder from the index instead of deleting the real folder in the local system |
| `git submodule add` \<repo_url\> \<path_name\> | Add the given repository as a submodule at the giver path |
| `git reset` \<file_name\> | Undo the specific file which you stage before commit |
| `git reset` | Undo all git add files |
| `git difftool --dir-diff` | Show unstaged changes (don't show new files) |
| `git difftool --cached --dir-diff` | Show staged changes (do show new files) |
| `git difftool HEAD~ --dir-diff` | Compare the difference between HEAD~ and HEAD |
| `git difftool` \<branch_1\>`..`\<branch_2\> `--dir-diff` | Compare two branches in git |

## Solutions

- [Adding an existing project to Github using the command line](https://docs.github.com/en/free-pro-team@latest/github/importing-your-projects-to-github/adding-an-existing-project-to-github-using-the-command-line)
- [Delete a folder in github, but not in local](https://stackoverflow.com/questions/15597828/delete-a-folder-in-github-but-not-in-local)
- [Difference between “git add -A” and “git add .”](https://stackoverflow.com/questions/572549/difference-between-git-add-a-and-git-add?rq=1)
- [Configuring a remote for a fork](https://docs.github.com/en/free-pro-team@latest/github/collaborating-with-issues-and-pull-requests/configuring-a-remote-for-a-fork)
- [Syncing a fork](https://docs.github.com/en/free-pro-team@latest/github/collaborating-with-issues-and-pull-requests/syncing-a-fork)
- [How to check if a local repo is up to date](https://stackoverflow.com/questions/7938723/git-how-to-check-if-a-local-repo-is-up-to-date)
- [How to remove a submodule](https://stackoverflow.com/questions/1260748/how-do-i-remove-a-submodule)
- [How to undo the most recent local commits in Git](https://stackoverflow.com/questions/927358/how-do-i-undo-the-most-recent-local-commits-in-git)
- [How to create a remote Git branch](https://stackoverflow.com/questions/1519006/how-do-you-create-a-remote-git-branch)
- [Basic writing and formatting syntax of README](https://docs.github.com/en/github/writing-on-github/basic-writing-and-formatting-syntax)
- [How do I check out a remote Git branch](https://stackoverflow.com/questions/1783405/how-do-i-check-out-a-remote-git-branch)
- [Managing your GitHub profile README](https://docs.github.com/en/account-and-profile/setting-up-and-managing-your-github-profile/customizing-your-profile/managing-your-profile-readme)
- [Checking out pull requests locally](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/reviewing-changes-in-pull-requests/checking-out-pull-requests-locally)
- [Creating a personal access token](https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token)
- [How to check real git diff before merging from remote branch](https://stackoverflow.com/questions/4944376/how-to-check-real-git-diff-before-merging-from-remote-branch)
