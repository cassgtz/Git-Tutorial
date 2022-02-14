# Git-Tutorial 
## What's git? 
Git is the most popular version control system in today’s world. Version control systems are software tools that allow you to manage and track changes made to files. Git runs locally and is accessible via command line (terminal). This means you can manage, track, and store your files on your local machine. Git is most commonly used with [Github](https://github.com), the online website that hosts your Git projects (or repositories) remotely. It is widely used because it allows for the non-linear, simultaneous collaboration on projects from anywhere, since repositories on Github can be accessed by others. 

In other words, Git is used to track and manage changes to files. This allows multiple people to work on the same project, at the same time, without impedeing on each other's work. This tutorial will go over the basic concepts needed to start using Git including cloning, branches, stashes, merges, and conflicts.

## Getting Started: Cloning 

We will be using a demo project for this tutorial. To get started, you will need to access the project located in the [Github repository](https://github.com/cassgtz/Git-Tutorial.git) and copy it onto your local machine. This is called **cloning**. 

**How to clone a GitHub repository:** 
1. Copy the URL in GitHub
![](githuburl.png)
2. Use the command `git clone <URL>` & hit enter
  
    This creates a folder in your local machine with the same name as the Github repository. 
  
    ![](clone.png)

Now you have the repository Git-Tutorial in your local machine. Let’s open up the demo.c file that is in Git-Tutorial. We will make changes to it in order to demonstrate the different git commands and concepts in this tutorial. It should look like this:

![](OGDemo.png)

## Commits
**Commit** is a Git command that saves changes in your repository. It is often described as a snapshot of your repository at the time you made the commit. Each commit takes a message as a way to label/track changes. 
Think of Google Docs as a comparison. When you look at the version history of a Google Doc, there are various timestamps that each correspond to a different version of the doc at the time that you saved it. A commit is just like saving a doc’s version with the commit’s message being the timestamp.

**How to commit changes:** 

1. Working directory: First you must make changes on your local machine. These changes only exist locally on your machine and are not reflected anywhere else. 

    Make a change to the file demo.c: Comment out the statement on line 5. 
    
    ![](comment.png)

2. Staging directory: When you are finished making changes, you must first add them to your staging directory. Think of this as you applying the changes to your repository but not yet saving them. 
    
    Add changes to staging directory by using the command `git add <FILENAME>` & hit enter
  
    ![](stage.png)

3. Commit: Once you are ready to save all the changes, do the commit command. This will reflect all changes in your repository. 

    Commit changes by using the command `git commit -m “MESSAGE”` & hit enter
  
    ![](commit.png)
    
This created a commit with the message "Removed Statement". The commited changes are now stored in the repository. 

## Branches
**Branching** is the most essential concept of git because it is what allows for non-linear development of projects. It the process of creating copies (branches) of objects in order to build upon them. Creating a branch craetes a pointer to a commit. In short, branches result in different versions of the same file for the purpose of isolating new changes without affecting original versions. 

When you initialize a repository, git automatically creates a default branch named "main". From the main branch, you can create as many branches as you want. In general, you may continue to create branches off of any branch by checkouting at the source branch first, then creating the new branch. 

**How to create a branch:** 
1. Move into the desired source branch using the command `git checkout <BRANCH NAME>` 
2. Create branch using the command `git branch “NAME OF BRANCH”`

Let's create 2 branches to work with. Create a "bday" & a "dday" branch that branch out from main branch: 
![](createBranches.png)

Now, let’s make changes in each branch & commit them. 

Bday branch:
  * To access the branch, move into it: `git checkout bday`
  * Replace the code in demo.c in the bday branch with:
      ```
      # include <stdio.h>

      int main(void) {
	      int piday = 314;
	      printf("%d\n", piday);

	      int bday = 323;
	      printf("%d\n", bday");

	      int vday = 214;
	      printf("%d\n", vday);

	  return 0;
    }
    ```
  * Commit changes!
  
Dday branch:
  * move into dday branch: `git checkout dday`
  * Replace the code in demo.c in the dday branch with:
      ```
      # include <stdio.h>

      int main(void) {
	      int piday = 314;
	      printf("%d\n", piday);

	      int dday = 606;
	      printf("%d\n", dday");

	      int vday = 214;
	      printf("%d\n", vday);

	  return 0;
    }
    ```
  * Commit changes!

Now, all three branches (main, bday, and dday) have different versions of the demo.c file. Note that the demo.c versions in bday & dday branches have different statements in the same line. This will be useful later. 

## Stashes
Now, let’s take a look at what happens when you stage changes in one branch, then try to checkout to another branch:

![](stashError.png)

An error message states that the staged changes will be discarded. You must either commit the changes or stash them. **Stashing** is used when you are not quite ready to commit changes but you need to change branches for whatever reason. The stash command temporarily stores staged changes so you can reapply them later. 

**How to stash changes:**
1. Stage changes to a branch. 
2. Stash with a message using the command `git stash save “MESSAGE”`

Stashes are stored in a list that is visible by using the command `git stash list`:

![](stashList.png)

This is a list of 1 stash. Each stash has an individual ID (`stash@{0}`).

When you are ready to reapply the stashed changes & stage them, use the command `git stash apply <STASH ID>`

## Merges

**Merging** is the process of combining changes from one branch to another, creating a **merge commit**. More specifically, it means taking all the contents of a source branch and apply them to a target branch. The target branch changes by integrating the source branch’s contents. 

**How to merge 2 branches:**
1. Checkout to the source branch `git checkout <SOURCE BRANCH NAME>`
2. Merge to target branch using command `git merge <TARGET BRANCH NAME>`

Let's merge our bday branch (source) with dday branch (target): 

![](conflict.png)


Conflicts arise if there is a change on the same line: remember both of our branches were changed on the same lines. Git does not know which change you want to override or if you want to keep both changes. Therefore, the merge cannot happen until you manually edit the files and choose what you want to keep.

These are the conflicts:

![](resolve.png)

Say we wanted to keep both versions. This is how we would resolve it:

![](ResolveDC.png)

Then, commit as usual. 

## Conclusion
This tutorial is meant to walk through the basic concepts needed to understand use Git. Git is full of many tools 
