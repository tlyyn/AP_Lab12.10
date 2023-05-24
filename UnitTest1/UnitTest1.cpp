#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab12.10/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		/*викликається функція insertNode для вставки значення 5. Потім проводяться перевірки для переконання,
		що функція insertNode правильно вставляє новий вузол в дерево.*/

		TEST_METHOD(TestMethod1)
		{
			// Arrange
			Node* root = nullptr;

			// Act
			root = insertNode(root, 5);

			// Assert
			Assert::IsNotNull(root);
			Assert::AreEqual(5, root->data);
			Assert::IsNull(root->left);
			Assert::IsNull(root->right);
		}
	};
}
