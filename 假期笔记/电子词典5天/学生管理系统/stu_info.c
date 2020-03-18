#include <stdio.h>

int main(int argc, char *argv[])
{
	char order[64];
	sqlite3 *db = NULL;
	char *errmsg = NULL;
	
	/*创建并打开数据库*/
	if (0 != sqlite3_open("stu_info.db", &db)) {
		fprintf(stderr, "sqlite3_open: %s\n", sqlite3_errmsg(db));
		return -1;
	} 

	/*创建学生信息表*/
	sqlite3_exec(db, "create table stu(id integer primary key, name text, age integer, score integer)", NULL, NULL, &errmsg); 

	while (1) {
		printf("*******************************************\n");
		printf("		1. 查询所有学生的信息 \n");
		printf("		2. 按名字查询学生信息 \n");
		printf("		3. 增加学生的信息 \n");
		printf("		4. 删除学生的信息 \n");
		printf("		5. 修改学生的信息 \n");
		printf("		6. 退出系统 \n");
		printf("*********输入想要选择功能的数字(1-6)***********\n");
#if 0
		if (1 != scanf("%d", &order)) {  //成功输入order , int order;
			fgets(buf, sizeof(buf), stdin);
			fprintf(stderr, "Input error, Again!\n");
			continue;
		}
		getchar();
#else
		fgets(order, sizeof(order), stdin);
		
		switch (order[0]) {
			case '1':
				do_query(db);
				break;
			case '2':
				do_name_query(db);
				break;
			case '3':
				do_insert(db);
				break;
			case '4':
				do_delete(db);
				break;
			case '5':
				do_update(db);
				break;
			case '6':
				sqlite3_close(db);
				exit(0);
				break;
			default:
				fprintf(stderr, "Input error, again!\n");
				break;
			
		}
#endif
	}

	return 0;
}
