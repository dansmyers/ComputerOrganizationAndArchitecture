# GitHub and Assignments

### Version Control

Git is a **version control system** designed to manage source code for large distributed projects. It was invented by Linus Torvalds, the creator of Linux, and inspired by the needs of that project. GitHub is a company providing cloud-based project hosting using Git.

Every large software project uses version control to track changes to its codebase. A modern VCS will track changes to files, allow for rollback to earlier working versions of the project, and control who is allowed to add and modify the project's files.

The basic organizational unit of Git is the **repository**, or **repo**. A single repo stores the files for a single project.

Git uses a **distributed** approach to source control, where multiple peers may each have their own indpendent copy of the repository, similar to peer-to-peer filesharing services like BitTorrent. For example, you may have a repository of your project stored in your Cloud9 workspace and a repository on GitHub. As you edit your project files on Cloud9, you can **push** changes from that repo into the GitHub repo.

Git is deep. The rest of this note will cover only the basics of Git and GitHub that you need to submit your projects.

### Creating Repositories

First, sign up for a GitHub account, if you haven't already done so. I'll wait right here.

Welcome back.

I've created a GitHub organizational account for our course named `rollinscms230`. When I create an assignment on this account, GitHub automatically generates a link that I will send to you. Click on that link and GitHub will create a new repo under `rollinscms230` to hold your assignment files.

For example, suppose I've created an assignment named `project1`. Clicking on the link will create a new repo tied to my GitHub username, `rollinscms230/project1-dansmyers`. I can visit the repo in my web browser at

```
http://github.com/rollinscms230/project1-dansmyers
```

Your repo will have your GitHub username in place of `dansmyers`.

Your repo is private: only you and I can access it. It will be initialized with files that I specify, typically a file named `README.md` and a copy of the project description.

### Cloning Your Repo to Cloud9

Once you have created a project repo on GitHub, you'll want to **clone** it to Cloud9 so you can work on the project. The files you create and change on Cloud9 will be pushed back to the GitHub repo.

Log in to your Cloud9 workspace and navigate to a directory where you want to store your project files. Once you're there, type

```
prompt$ git clone https://github.com/rollinscms230/project1-dansmyers
```

You'll replace `dansmyers` with your own username. Note the use of `https` in the URL: this is a secure login and you'll be prompted for your GitHub username and password. You should see output that looks something like this:

```
dmyers@cms230:~/temp $ git clone https://github.com/rollinscms230/project1-dansmyers
Cloning into 'project1-dansmyers'...
Username for 'https://github.com': dansmyers
Password for 'https://dansmyers@github.com': 
remote: Counting objects: 9, done.
remote: Compressing objects: 100% (6/6), done.
remote: Total 9 (delta 1), reused 9 (delta 1), pack-reused 0
Unpacking objects: 100% (9/9), done.
Checking connectivity... done.
```

The result will be a new directory named `project1-dansmyers` that contains all of the files in the initial repo. `cd` into this directory and begin working on your project.

### Pushing Changes

Suppose that you've made a new file called `problem1.c` and you're ready to push it from the local Cloud9 repo to the GitHub repo.

First, you must keep in mind that the two repos are independent of each other. Changes in one are **not** automatically tracked by the other. Any time you **create or change** a file on Cloud9, you must manually push those changes back to GitHub.

This process has two steps. First, you'll **commit** the changes you've made to the local Cloud9 repo. Second, you'll **push** the changes you've made in the local repo to the GitHub repo.


**Commitment**

To commit a file to the repo, you first **stage** it with the **add** command:

```
prompt$ git add problem1.c
```

This indicates to Git that you intend to add `problem1.c` to the local repo on the next commit action. If you have more files that you've created or changed, add them in a similar way&mdash;you can commit multiple files in one action.

Once the file has been added to the staging area, you can commit to the local repo with

```
prompt$ git commit -m "Added problem1.c"
```

The `-m` flag specifies a message that is included with the commit describing its purpose. If you don't include a message with `-m`, git will open a text editor in the terminal asking you to enter a message.

This will produce output similar to

```
[master 4669405] Added problem1.c
 1 file changed, 1 insertion(+)
 create mode 100644 problem1.c
 ```
 
 The file has now been added to the local repo. 
 
**Push**

 To push it to the remote GitHub repo, use
 
 ```
 prompt$ git push origin master
 ```
 
For murky reasons, the local copy of the repository (the source of the pushed files) is referred to as `master` and the remote location (the target of the push operation) is `origin`. The command specifies that any changes to `master` should be pushed to `origin` to bring them into sync.

You'll be prompted again for your GitHub credentials, then see some output like this:

```
Username for 'https://github.com': dansmyers
Password for 'https://dansmyers@github.com': 
Counting objects: 4, done.
Delta compression using up to 8 threads.
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 270 bytes | 0 bytes/s, done.
Total 3 (delta 1), reused 0 (delta 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local objects.
To https://github.com/rollinscms230/project1-dansmyers
   fa3617f..4669405  master -> master
```

Refreshing the GitHub repo at `http://github.com/rollinscms230/project1-dansmyers` shows that `problem1.c` has now appeared.

One technical point: the target of the push operation was automatically configured by the initial clone operation. Pushing to a different repo would require an additional command to change the target.

### Git With It

This is the absolute bare minimum of Git knowledge you need to execute the projects. Git and GitHub have a huge number of features that we don't have the time to explore now. 

In particular, Git supports the idea of **branching** to create parallel copies of a repository. This feature is typically used if multiple developers are adding new features to a project in parallel: each developer works on her own branch of the code, then the branches are merged back into the master codebase when they're complete. This approach keeps the production codebase clean and prevents the developers from interfering with each other while their work is in progress.
