#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void parent_process_func()
{
	printf("parent_process_func\n");

	int status;
	// 子プロセスの終了するまで呼び出しプロセスを中断
	pid_t ret = wait(&status);
	
	if(ret < 0)
	{
		fprintf(stderr, "Wait Error.\n\n");
		exit(-1);
	}
	
	// 終了ステータスのチェック
	if(WIFEXITED(status))
	{
		printf("子プロセス終了コード(%d)\n", WEXITSTATUS(status));
	}
	else
	{
		printf("プロセス終了失敗コード(%d)\n", status);
	}
	
	// シグナルによる終了
	if (WIFSIGNALED(status))
	{
		printf("シグナル番号により終了(%d)\n", WTERMSIG(status));
	}	
	printf("親プロセス終了\n");
}

void child_process_func()
{
	printf("child_process_func\n");
	sleep(5);
}

// fork時は，グローバル変数や関数内のstatic変数もコピーされる
int tmp = 1;

int main(int argc, char **argv)
{
	// 子プロセス起動
	pid_t pid = fork();

	// マルチスレッド時にforkは行わない(場合によってはデッドロックが発生する)
	// 回避策としてfork直後に子プロセス(forkの戻り値0)がexecを呼ぶようにする
	// forkが必要な時はforkの時に特殊な処理を書きpthread_atfork()で登録すること
	
	// fork失敗
	if(pid == -1)
	{
		fprintf(stderr, "fork error\n");
	}

	printf("fork id : %d, current process id : %d, parent process id : %d\n",
	       pid, getpid(), getppid());
	
	if(pid == 0)
	{
		printf("tmp = %d\n", tmp);
		// 子プロセスはforkの戻り値が0になる
		child_process_func();
	}
	else
	{
		printf("tmp = %d\n", tmp);
		// 親プロセスの処理
		parent_process_func();
	}
	
	return 0;
}
