
int main(void)
{
	int arr[] = {2, 7, 3, 10 ,8, 5, 9, 88, 53};

	int n = sizeof(arr) / sizeof(arr[0]);	// ��ȡ����Ԫ�ظ���

	int i = 0;					// ��С�±�
	int j = n - 1;				// ����±ꡣ
	int temp = 0;

	while (i < j)
	{
		temp = arr[i];			// ����ˮ�� ���� arr[i] �� arr[j] ����������
		arr[i] = arr[j];
		arr[j] = temp;
		i++;					// ����С�±����
		j--;					// ������±���ǰ
	}
	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}