//array.cpp
//
#include "array.h"

CArray::CArray(int sz) : aidx(0)
{
	if (sz <= 0)
		return;
	size = sz;
	arr = new ArrayElm[size]; //절대 변경 불가...이 명령문을 임의로 변경하지 마시오.
}

CArray::~CArray()
{
	delete[] arr; //절대 변경 불가...이 명령문을 임의로 삭제하시 마시오.
}

void CArray::Update(ArrayElm data, int idx)
{
	if (idx < 0 || idx >= size)
		return;
	arr[idx] = data;
}

void CArray::Insert(ArrayElm data, int idx)
{
	if (aidx == size)
		return;
	if (idx < 0 || aidx < idx)
		return;
	else if (aidx == idx)
		arr[aidx++] = data;
	else
	{
		for (int i = aidx - idx, j = aidx; i>0; i--, j--)
			arr[j] = arr[j - 1];
		arr[idx] = data;
		aidx++;
	}
}

void CArray::Insert(ArrayElm data)
{
	if (aidx == size)
		return;
	arr[aidx++] = data;
}

void CArray::Remove(int idx)
{
	if (idx < 0 || idx >= aidx)
		return;
	for (int i = idx; i < aidx - 1; i++)
		arr[i] = arr[i + 1];
	aidx--;
}

ArrayElm CArray::GetItem(int idx)
{
	if (idx < 0 || idx >= aidx)
		return ArrayElm();
	return arr[idx];
}