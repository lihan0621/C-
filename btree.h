#pragma once
typedef char DataType;

typedef struct BNode
{
	DataType _data;
	struct BNode* _left;
	struct BNode* _right;
}BNode;
