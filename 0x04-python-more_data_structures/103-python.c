#include <stdio.h>

/**
 * print_python_bytes - Prints bytes information
 *
 * @p: Python Object
 * Return: no return
 */
void print_python_bytes(PyObject *p)
{
	if (PyBytes_Check(p))
	{
		printf("[.] bytes object info\n");
		printf("  size: %ld\n", PyBytes_Size(p));
		printf("  trying string: %s\n", PyBytes_AsString(p));
		printf("  first %d bytes: ", PyBytes_Size(p) < 10 ? PyBytes_Size(p) : 10);

		for (int i = 0; i < PyBytes_Size(p) && i < 10; i++)
		{
			printf("%02x ", (unsigned char)PyBytes_AS_STRING(p)[i]);
		}
		printf("\n");
	}
	else
	{
		printf("[ERROR] Invalid Bytes Object\n");
	}
}

/**
 * print_python_list - Prints list information
 *
 * @p: Python Object
 * Return: no return
 */
void print_python_list(PyObject *p)
{
	long int size, i;
	PyListObject *list;
	PyObject *obj;

	size = ((PyVarObject *)(p))->ob_size;
	list = (PyListObject *)p;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", list->allocated);

	for (i = 0; i < size; i++)
	{
		obj = ((PyListObject *)p)->ob_item[i];
		printf("Element %ld: %s\n", i, ((obj)->ob_type)->tp_name);
		if (PyBytes_Check(obj))
			print_python_bytes(obj);
	}
