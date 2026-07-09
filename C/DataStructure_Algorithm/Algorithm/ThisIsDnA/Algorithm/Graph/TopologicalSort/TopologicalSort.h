#pragma once
#include "graph.h"
#include "linked_list.h"

void TopologicalSort(Vertex* v, ListNode** list);
void dfs(Vertex* v, ListNode** list);