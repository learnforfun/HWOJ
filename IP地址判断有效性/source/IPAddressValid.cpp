#include "IPAddressValid.h"
#include "stdio.h"

bool isIPAddressValid(const char* pszIPAddr)
{
	// 请在此处实现
	const char* start = pszIPAddr;
	const char* end = 0;
	const char* temp = 0;

	// 检查字符串起始地址不为0
	if (!start)
	{
		return false;
	}

	// 忽略字符串前后的空格
	while (*start)
	{
		if (*start == ' ')
		{
			start++;
		}
		else
		{
			break;
		}
	}
	for (end = start; *end; end++)
		;
	end--;
	while (end != start)
	{
		if (*end == ' ')
		{
			end--;
		} 
		else
		{
			break;
		}
	}

	// 确保start和end之间全为数字及点分隔符
	for (temp = start; temp <= end; temp++)
	{
		if ((*temp < '0' || *temp > '9') && *temp != '.')
		{
			return false;
		}
	}

	// 确保含有3个点分隔符
	int dots=0;
	for (temp = start; temp <= end; temp++)
	{
		if (*temp == '.')
		{
			dots++;
		}
	}
	if (dots!=3)
	{
		return false;
	}

	// 确保每段字符串不为空且对应数值不大于255
	int len=0,sum=0;
	for (temp = start; temp <= end; temp++)
	{
		if (*temp != '.'  && temp != end)
		{
			len++;
			continue;
		}

		if (*temp == '.' && temp == end)
		{
			return false;
		}

		if (temp == end)
		{
			len++;
			temp++;
		}

		if (len == 0 || len > 3)
		{
			return false;
		}
		
		// 确保子段长度大于1时不以0开头
		if (len >1 && *(temp - len) == '0')
		{
			return false;
		}
		else
		{
			sum = 0;
			while (len)
			{
				sum *= 10;
				sum += *(temp-len) - '0';
				len--;
			}
			if (sum > 255)
			{
				return false;
			}
		}
	}

	return true;
}