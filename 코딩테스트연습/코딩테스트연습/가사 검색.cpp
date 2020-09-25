#include <string>
#include <vector>

/** 
* ȿ�������� ������ ����.
* Trie ������ Ǯ��� �ϴ� ��. ( Trie �����ε� �� Ǯ���. )
* 
* @See : https://programmers.co.kr/learn/courses/30/lessons/60060
*/

using namespace std;

size_t FindMathStringWithFrontQuestion(const vector<string>& words, const string& queries)
{
	size_t resultCount = 0;

	string strTemp = "";
	size_t count = 0;
	for (const char& c : queries)
	{
		if (c == '?')
			count += 1;
		else
			strTemp += c;
	}

	vector<string> temp; temp.reserve(words.size());

	for (size_t i = 0; i < words.size(); ++i)
	{
		string str = words[i];
		string str2 = "";
		for (size_t j = count; j < str.size(); ++j)
		{
			str2 += str[j];
		}

		if (str2 == strTemp)
			resultCount += 1;
	}

	return resultCount;
}

size_t FindMathStringWithBehindQuestion(const vector<string>& words, const string& queries)
{
	size_t count = 0;
	string strTemp = "";
	for (const char& c : queries)
	{
		if (c == '?')
			count += 1;
		else
			strTemp += c;
	}

	vector<string> temp; temp.reserve(words.size());

	for (size_t i = 0; i < words.size(); i++)
	{
		bool isExist = true;

		for (size_t j = 0; j < strTemp.size(); ++j)
		{
			if (strTemp[j] != words[i][j])
				isExist = false;
		}
		if (isExist)
			temp.push_back(words[i]);
	}

	size_t startPoint = strTemp.size();
	size_t resultCount = 0;
	for (size_t i = 0; i < temp.size(); ++i)
	{
		string str = temp[i];

		if (count == (str.size() - startPoint))
		{
			resultCount += 1;
		}
	}
	return resultCount;
}
vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<int> answer;

	for (size_t i = 0; i < queries.size(); i++)
	{
		char c = queries[i][0];
		int n = 0;
		switch (c)
		{
		case '?':
			n = FindMathStringWithFrontQuestion(words, queries[i]);
			answer.push_back(n);
			break;
		default:
			n = FindMathStringWithBehindQuestion(words, queries[i]);
			answer.push_back(n);
			break;
		}
	}
    return answer;
}

int main()
{
	solution({ "frodo", "front", "frost", "frozen", "frame", "kakao" }, { "fro??", "????o", "fr???", "fro???", "pro?" });
}