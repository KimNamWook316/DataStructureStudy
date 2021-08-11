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

			// 작은 따옴표 안일때
			if (bIsSingleQ) {
				// '\\' 이스케이프 문자일 경우 처리
				if ('\\' == prevCh && '\\' == ch) {
					prevCh = '\'';
					continue;
				}
				// 작은 따옴표 다시 만나면
				if ('\'' == ch) {
					// 이스케이프 문자 \' 이면 닫기 처리 안함
					if ('\\' == prevCh) {
						prevCh = ch;
						continue;
					} else {
						bIsSingleQ = false;
						prevCh = ch;
						continue;
					}
				} else {
					// 작은 따옴표 안에서는 괄호 처리 안함
					prevCh = ch;
					continue;
				}
			}

			// 큰 따옴표 안일 때
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

			// 작은 따옴표 처음 만났을 때
			if (!bIsSingleQ && '\'' == ch) {
				bIsSingleQ = true;
			}

			// 큰 따옴표 처음 만났을 때
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
		printf("[%s] 파일 검사 결과:\n", fileName);
		if (!stack.IsEmpty()) {
			stack.Display();
			printf("Error : 문제발견!(라인수=%d, 문자수=%d)\n\n", nLine, nChar);
		} else {
			printf("Error : 괄호닫기정상(라인수=%d, 문자수=%d)\n\n", nLine, nChar);
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