#include "pch.h"
#include "CppUnitTest.h"
#include "../3laba/tree.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My3labatest
{
	TEST_CLASS(My3labatest)
	{
	public:
		
		TEST_METHOD(IternoEmptyTest)
		{
			Binary_tree tree;
			tree.insert(1);
			Iterator* iter = tree.create_dft_iterator();
			Assert::IsTrue(iter->next() == 1);
		}
		TEST_METHOD(IterEmptyTest)
		{
			Binary_tree tree;
			try
			{
				Iterator* iter = tree.create_dft_iterator();
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "This tree is empty");
			}
		}
		TEST_METHOD(IterWidthTest)
		{
			Binary_tree tree;
			int arr[10] = {7,4,9,1,6,8,0,3,5,2 };
			for (int i = 0; i < 10; i++) tree.insert(arr[i]);
			Iterator* iter = tree.create_bft_iterator();
			for (int i = 0; i < 10; i++) Assert::IsTrue(arr[i] == iter->next());
		}
		TEST_METHOD(IterDepthTest)
		{
			Binary_tree tree;
			int arr[10] = { 7, 4, 1, 0, 3, 2, 6, 5, 9, 8 };
			for (int i = 0; i < 10; i++) tree.insert(arr[i]);
			Iterator* iter = tree.create_dft_iterator();
			for (int i = 0; i < 10; i++) Assert::IsTrue(arr[i] == iter->next());
		}
		TEST_METHOD(ContainsRealTest)
		{
			Binary_tree tree;
			int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
			for (int i = 0; i < 10; i++) {
				tree.insert(arr[i]);
				Assert::IsTrue(tree.contains(arr[i]));
			}
		}
		TEST_METHOD(ContainsUnRealTest)
		{
			Binary_tree tree;
			int arr[4] = { 1,2,3,4 };
			for (int i = 0; i < 4; i++) {
				tree.insert(arr[i]);
			}
			Assert::IsFalse(tree.contains(6));
		}
		TEST_METHOD(ContainsEmptyTreeTest)
		{
			Binary_tree tree;
			try {
				tree.contains(1);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "This tree is Empty!");
			}

		}
		TEST_METHOD(RemovenoEmptyTest)
		{
			Binary_tree tree;
			int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
			for (int i = 0; i < 10; i++) tree.insert(arr[i]);
			tree.remove(5);
			Assert::IsFalse(tree.contains(5));
		}
		TEST_METHOD(RemoveunRealTest)
		{
			Binary_tree tree;
			int arr[10] = {1,2,3,4,5,6,7,8,9,10 };
			for (int i = 0; i < 10; i++) tree.insert(arr[i]);
			try
			{
				tree.remove(11);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "This element isn`t in tree");
			}
		}
		TEST_METHOD(RemoveEmptyTest)
		{
			Binary_tree tree;
			try
			{
				tree.remove(1);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "This tree is Empty!");
			}
		}


	};
}
