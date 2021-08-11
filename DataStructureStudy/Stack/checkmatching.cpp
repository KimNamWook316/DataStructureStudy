#include "ArrayStack.h"

bool checkMatching(const char* fileName) {
	FILE* fp = nullptr;
	errno_t error = fopen_s(&fp, fileName, "rt");
	if (0 == error) {
		int nLine = 1;
		int nChar = 0;

		ArrayStack stack;
		char ch;
		char prevCh = '\0';
		
		bool bIsSingleC = false;
		bool bIsMultiC = false;
		bool bIsSingleQ = false;
		bool bIsDoubleQ = false;

		while ((ch = getc(fp)) != EOF) {
			if ('\n' == ch) {
				++nLine;
				bIsSingleC = false;
			}
			++nChar;

			if (bIsMultiC && '*' == prevCh && '/' == ch) {
				bIsMultiC = false;
			}

			if (bIsSingleC) {
				prevCh = ch;
				continue;
			}

			if (bIsMultiC) {
				prevCh = ch;
				continue;
			}

			if ('*' == ch && '/' == prevCh && !bIsMultiC && !bIsSingleC) {
				bIsMultiC = true;
			}

			if ('/' == ch && '/' == prevCh && !bIsSingleC && !bIsMultiC) {
				bIsSingleC = true;
			}

			// ���� ����ǥ ���϶�
			if (bIsSingleQ) {
				// '\\' �̽������� ������ ��� ó��
				if ('\\' == prevCh && '\\' == ch) {
					prevCh = '\'';
					continue;
				}
				// ���� ����ǥ �ٽ� ������
				if ('\'' == ch) {
					// �̽������� ���� \' �̸� �ݱ� ó�� ����
					if ('\\' == prevCh) {
						prevCh = ch;
						continue;
					} else {
						bIsSingleQ = false;
						prevCh = ch;
						continue;
					}
				} else {
					// ���� ����ǥ �ȿ����� ��ȣ ó�� ����
					prevCh = ch;
					continue;
				}
			}

			// ū ����ǥ ���� ��
			if (bIsDoubleQ) {
				if ('\"' == ch) {
					if ('\\' == prevCh) {
						prevCh = ch;
						continue;
					} else {
						bIsDoubleQ = false;
						prevCh = ch;
						continue;
					}
				} else {
					prevCh = ch;
					continue;
				}
			}

			// ���� ����ǥ ó�� ������ ��
			if (!bIsSingleQ && '\'' == ch) {
				bIsSingleQ = true;
			}

			// ū ����ǥ ó�� ������ ��
			if (!bIsDoubleQ && '\"' == ch) {
				bIsDoubleQ = true;
			}

			if ('[' == ch || '(' == ch || '{' == ch) {
				stack.Push(ch);
			} else if (']' == ch || ')' == ch || '}' == ch) {
				int prev = stack.Peek();
				if((']' == ch && '[' == prev) || 
					(')' == ch && '(' == prev) ||
					('}' == ch && '{' == prev)) {
					stack.Pop();
				}
			}

			prevCh = ch;
		}

		fclose(fp);
		printf("[%s] ���� �˻� ���:\n", fileName);
		if (!stack.IsEmpty()) {
			stack.Display();
			printf("Error : �����߰�!(���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
		} else {
			printf("Error : ��ȣ�ݱ�����(���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
		}
		return stack.IsEmpty();
	} else {
		printf("error");
	}
}

void main() {
	//checkMatching("ArrayStack.h");
	checkMatching("checkMatching.cpp");
	//checkMatching("test.txt");
	checkMatching("test2.txt");
}