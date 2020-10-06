/*
 * -*- coding: utf-8 -*-
 * @Time    : 2020/10/5 0:16
 * @Author  : nieyuzhou
 * @File    : utilities.h/cpp
 * @Software: CLion
 */


#ifndef CACULATOR_LINKLIST_H
#define CACULATOR_LINKLIST_H

#include "utilities.h"

void init(LinkList **L);
void initList(LinkList **L, string &expression);
void polyCal(LinkList **first, LinkList **second, LinkList **result, char c);
void grad(LinkList **input);


#endif //CACULATOR_LINKLIST_H