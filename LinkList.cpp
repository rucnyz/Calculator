/*
 * -*- coding: utf-8 -*-
 * @Time    : 2020/10/5 18:44
 * @Author  : nieyuzhou
 * @File    : LinkList.h/cpp
 * @Software: CLion
 */
#include "LinkList.h"

void init(LinkList **L)
{
	//初始化结点
	*L = (LinkList *) malloc(sizeof(LinkList));
	(*L)->next = nullptr;

}


void initList(LinkList **L, string &expression)
{
	vector<string> tmp;
	tmp = split(expression, '+', '-');
	parser(tmp, &L);
}

void polyCal(LinkList **first, LinkList **second, LinkList **result, char c)
{
	while (true)
	{
		//前者到达末端
		if (*first == nullptr)
		{
			if (c == '+')
			{
				(*result)->data.parameter = (*second)->data.parameter;
			}
			else if (c == '-')
			{
				(*result)->data.parameter = -(*second)->data.parameter;
			}
			(*result)->data.power = (*second)->data.power;
			(*second) = (*second)->next;
		}//后者到达末端
		else if ((*second) == nullptr)
		{
			(*result)->data.parameter = (*first)->data.parameter;
			(*result)->data.power = (*first)->data.power;
			(*first) = (*first)->next;
		}//均未到达末端，则比较指数，较大者被存入结果，并后移；
		else if ((*first)->data.power != (*second)->data.power)
		{
			if ((*first)->data.power > (*second)->data.power)
			{

				(*result)->data.parameter = (*first)->data.parameter;
				(*result)->data.power = (*first)->data.power;
				(*first) = (*first)->next;


			}
			else
			{
				if (c == '+')
				{
					(*result)->data.parameter = (*second)->data.parameter;
				}
				else if (c == '-')
				{
					(*result)->data.parameter = -(*second)->data.parameter;
				}
				(*result)->data.power = (*second)->data.power;

				(*second) = (*second)->next;


			}
		}//均未达到末端，两者指数相同，计算后存入结果；均后移
		else
		{
			(*result)->data.power = (*first)->data.power;
			if (c == '+')
			{
				(*result)->data.parameter = (*first)->data.parameter + (*second)->data.parameter;
			}
			else if (c == '-')
			{
				(*result)->data.parameter = (*first)->data.parameter - (*second)->data.parameter;
			}
			(*first) = (*first)->next;
			(*second) = (*second)->next;

		}
		if (*first == nullptr && *second == nullptr)
		{
			break;
		}
		init(&(*result)->next);
		(*result) = (*result)->next;
	}
}


void grad(LinkList **input)
{
	if ((*input)->data.power == 0)
	{
		(*input)->data.parameter = 0;
		return;
	}
	(*input)->data.parameter = (*input)->data.parameter * (*input)->data.power;
	(*input)->data.power = (*input)->data.power - 1;
	while ((*input)->next != nullptr)
	{
		if ((*input)->next->data.power == 0)
		{
			(*input)->next = nullptr;
			break;
		}
		(*input) = (*input)->next;
		(*input)->data.parameter = (*input)->data.parameter * (*input)->data.power;
		(*input)->data.power = (*input)->data.power - 1;
	}
}
