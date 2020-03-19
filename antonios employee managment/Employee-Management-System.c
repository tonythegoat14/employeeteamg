#include<stdio.h>
#include<string.h>

int emp_count=0; //global variable created for emp_count
//char name1[24];

struct employee
{
	int emp_id;
	char name[24];
	char mob_no[10];
	float basicSalary;
	float hra;
	float da;
	float grossSalary;
};

struct employee emp[10];

void insert_employee_record()
{

		if(emp_count<3)
		{

			printf("Enter Employee ID: ");
			scanf("%d",&emp[emp_count].emp_id);
			printf("\n");
			printf("Enter Employee Name: ");
			fflush(stdin);
			gets(emp[emp_count].name);
			printf("\n");
			printf("Enter Mobile Number: ");
			scanf("%s",&emp[emp_count].mob_no);
			printf("\n");
			printf("Enter Basic Salary: ");
			scanf("%f",&emp[emp_count].basicSalary);
			printf("\n\n");




			if(emp[emp_count].basicSalary<=2000)
			{
				emp[emp_count].hra=(0.25*emp[emp_count].basicSalary);
				emp[emp_count].da=(0.15*emp[emp_count].basicSalary);
				emp[emp_count].grossSalary=emp[emp_count].basicSalary+emp[emp_count].hra+emp[emp_count].da;
			}

			else if(emp[emp_count].basicSalary>2000&&emp[emp_count].basicSalary<5000)
			{
				emp[emp_count].hra=(0.20*emp[emp_count].basicSalary);
				emp[emp_count].da=(0.10*emp[emp_count].basicSalary);
				emp[emp_count].grossSalary=emp[emp_count].basicSalary+emp[emp_count].hra+emp[emp_count].da;
			}

			else
			{
				emp[emp_count].hra=(0.10*emp[emp_count].basicSalary);
				emp[emp_count].da=(0.05*emp[emp_count].basicSalary);
				emp[emp_count].grossSalary=emp[emp_count].basicSalary+emp[emp_count].hra+emp[emp_count].da;
			}

			emp_count++;
	}
	else
	printf("\nYou Can Not Insert More Employee!!!\n\n");
}

void insert_employee_record_name(int index_name)
{

		printf("Enter Employee Name: ");
		scanf("%s",&emp[index_name].name);
		printf("\n");
		fflush(stdin);
}

int insert_employee_record_number(int index_number)
{
		printf("Enter Mobile Number: ");
		scanf("%s",&emp[emp_count].mob_no);
		printf("\n");
}

int insert_employee_record_basicsalary(index_basicsalary)
{
		printf("Enter Basic Salary: ");
		scanf("%f",&emp[index_basicsalary].basicSalary);
		printf("\n");


			if(emp[index_basicsalary].basicSalary<=2000)
			{
				emp[index_basicsalary].hra=(0.25*emp[index_basicsalary].basicSalary);
				emp[index_basicsalary].da=(0.15*emp[index_basicsalary].basicSalary);
				emp[index_basicsalary].grossSalary=emp[index_basicsalary].basicSalary+emp[index_basicsalary].hra+emp[index_basicsalary].da;
			}

			else if(emp[index_basicsalary].basicSalary>2000&&emp[index_basicsalary].basicSalary<5000)
			{
				emp[index_basicsalary].hra=(0.20*emp[index_basicsalary].basicSalary);
				emp[index_basicsalary].da=(0.10*emp[index_basicsalary].basicSalary);
				emp[index_basicsalary].grossSalary=emp[index_basicsalary].basicSalary+emp[index_basicsalary].hra+emp[index_basicsalary].da;
			}

			else
			{
				emp[index_basicsalary].hra=(0.10*emp[index_basicsalary].basicSalary);
				emp[index_basicsalary].da=(0.05*emp[index_basicsalary].basicSalary);
				emp[index_basicsalary].grossSalary=emp[index_basicsalary].basicSalary+emp[index_basicsalary].hra+emp[index_basicsalary].da;
			}

}

void edit_emp_record()
{
	int choice;
	printf("\nPress the option you want to change:-\n\n");

	printf("(1).Edit Employee Name\n\n");
	printf("(2).Edit Mobile Number\n\n");
	printf("(3).Edit Basic Salary\n\n");

	printf("Enter your choice: ");
	scanf("%d",&choice);
	system("cls");

	switch(choice)
	{
		case 1:
			printf("Edit Employee name:-");
			int input_id_name,index_name;
			printf("\n\nEnter Employee ID: ");
			scanf("%d",&input_id_name);
			index_name=search_emp_record(input_id_name);
			printf("\n");
			if (index_name!=-1)
				insert_employee_record_name(index_name);
			break;

		case 2:
			printf("Edit Mobile Number:-");
			int input_id_number,index_number;
			printf("\n\nEnter Employee ID: ");
			scanf("%d",&input_id_number);
			index_number=search_emp_record(input_id_number);
			printf("\n");
			if (index_number!=-1)
				insert_employee_record_number(index_number);
			break;

		case 3:
			printf("Edit Basic Salary:-");
			int input_id_basicsalary,index_basicsalary;
			printf("\n\nEnter Employee ID: ");
			scanf("%d",&input_id_basicsalary);
			index_basicsalary=search_emp_record(input_id_basicsalary);
			printf("\n");
			if (index_basicsalary!=-1)
				insert_employee_record_basicsalary(index_basicsalary);
			break;
		default:
			printf("Enter correct choice");

	}

}

void display_emp_record()
{
	int count;
	for(count=0;count<emp_count;count++)
	{
				printf("Your Employee ID: %d\n",emp[count].emp_id);
				printf("Your Employee Name: %s\n",emp[count].name);
				printf("Your Mobile Number: %s\n",emp[count].mob_no);
				printf("Your Basic Salary: %f\n",emp[count].basicSalary);
				printf("Your HRA is: %f\n",emp[count].hra);
				printf("Your DA is: %f\n",emp[count].da);
				printf("Your Gross Salary is: %f\n",emp[count].grossSalary);
				printf("\n\n");
	}
}

int search_emp_record(int input_id)
{
	int index;
	for(index=0;index<emp_count;index++)
	{
		if(input_id==emp[index].emp_id)
		{
			printf("\nYou have inserted ID Number: %d\n\n",input_id);
			printf("Your Employee ID: %d\n",emp[index].emp_id);
			printf("Your Employee Name: %s\n",emp[index].name);
			printf("Your Mobile Number: %s\n",emp[index].mob_no);
			printf("Your Basic Salary: %f\n",emp[index].basicSalary);
			printf("Your HRA is: %f\n",emp[index].hra);
			printf("Your DA is: %f\n",emp[index].da);
			printf("Your Gross Salary is: %f\n",emp[index].grossSalary);
			return index;
		}
	}
	printf("Your ID is not found!!!");
	return -1;


}

void main()
{
	int choice;
	do
	{
	printf("\nPress the number for following options :-\n\n");

	printf("(1).Insert Employee Record\n\n");
	printf("(2).Edit Employee Record\n\n");
	printf("(3).Display Employee Record\n\n");
	printf("(4).Search Employee Record\n\n");
	printf("(5).Exit\n\n");


	printf("Enter your choice: ");
	scanf("%d",&choice);
	system("cls");

	switch(choice)
	{
		case 1:
			printf("\nInsert Employee Record:-\n\n");
			insert_employee_record();
			break;

		case 2:
			printf("\nEdit Employee Record:-\n\n");
			edit_emp_record();
			break;

		case 3:
			printf("\nDisplay Employee Record:-\n\n");
			display_emp_record();
			break;

		case 4:
			printf("Search Employee Record:-\n\n");
			int input_id,index=0;
			printf("Enter Employee ID: ");
			scanf("%d",&input_id);
			search_emp_record(input_id);
			break;

		case 5:
			printf("You are exit from the program!!!");
			exit(0);
			break;

		default:
			printf("Please enter correct choice!!!");
			break;
	}

}while(1);
}
