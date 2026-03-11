#include <iostream>

template< class T >
struct List {
  T val;
  List< T >* next;
};
template< class T >
void clearRow(List< T >* head)
{
  while (head) {
    List< T >* head_new = head->next;
    delete head;
    head = head_new;
  }
}
template< class T >
void clear(List< List< T >* >* head)
{
  while (head) {
    List< List< T >* >* head_new = head->next;
    clearRow(head->val);
    delete head;
    head = head_new;
  }
}
template< class T >
List< T >* convertRow(const T* row, size_t size)
{
  List< T >* head = new List< T >{row[0], nullptr};
  List< T >* current = head;
  for (size_t i = 1; i < size; i++) {
    try {
      List< T >* node = new List< T >{row[i], nullptr};
      current->next = node;
      current = node;
    } catch (...) {
      clearRow(head);
      throw;
    }
  }
  return head;
}
template< class T >
List< List< T >* >* convert(const T* const* a, size_t s, const size_t* sa)
{
  List< List< T >* >* head = new List< List< T >* >;
  try {
    head->val = convertRow(a[0], sa[0]);
    head->next = nullptr;
  } catch (...) {
    delete head;
    throw;
  }
  List< List< T >* >* current = head;
  for (size_t i = 1; i < s; i++) {
    List< T >* row = nullptr;
    try {
      row = convertRow(a[i], sa[i]);
    } catch (...) {
      clear(head);
      throw;
    }
    try {
      List< List< T >* >* node = new List< List< T >* >{row, nullptr};
      current->next = node;
      current = node;
    } catch (...) {
      clearRow(row);
      clear(head);
      throw;
    }
  }
  return head;
}
void testConvert()
{
  size_t n = 4;
  size_t* sa = new size_t[n]{2, 3, 2, 3};
  int** mtx = nullptr;
  try {
    mtx = new int*[n];
  } catch (const std::bad_alloc&) {
    delete[] sa;
    throw;
  }

  size_t i = 0;
  try {
    for (; i < n; i++) {
      mtx[i] = new int[sa[i]];
      for (size_t k = 0; k < sa[i]; k++) {
        mtx[i][k] = i;
      }
    }
  } catch (const std::bad_alloc&) {
    for (size_t j = 0; j < i; j++) {
      delete[] mtx[j];
    }
    delete[] mtx;
    delete[] sa;
    throw;
  }

  List< List< int >* >* list = nullptr;
  try {
    list = convert(mtx, n, sa);
  } catch (...) {
    for (size_t j = 0; j < i; j++) {
      delete[] mtx[j];
    }
    delete[] mtx;
    delete[] sa;
    throw;
  }
  List< List< int >* >* current = list;
  for (size_t j = 0; j < n; j++) {
    List< int >* current_row = current->val;
    for (size_t k = 0; k < sa[j]; k++) {
      std::cout << current_row->val << '\n';
      current_row = current_row->next;
    }
    current = current->next;
  }

  for (size_t j = 0; j < i; j++) {
    delete[] mtx[j];
  }
  delete[] mtx;
  delete[] sa;

  clear(list);
}

template< class T >
struct Vector {
  T* data;
  size_t s;
};
template< class T >
struct ListOfVecIt {
  List< Vector< T > >* curr;
  size_t i;
};
template< class T >
ListOfVecIt< T > begin(List< Vector< T > >* h)
{
  return {h, 0};
}
template< class T >
bool hasNext(ListOfVecIt< T > it)
{
  if (it.i < it.curr->val.s - 1) {
    return true;
  }
  if (it.curr->next) {
    return true;
  }
  return false;
}
template< class T >
ListOfVecIt< T > next(ListOfVecIt< T > it)
{
  if (it.i < it.curr->val.s - 1) {
    return {it.curr, it.i + 1};
  }
  return {it.curr->next, 0};
}
void testListOfVecIt()
{
  size_t n1 = 5, n2 = 3;
  Vector< int > vec1{nullptr, n1};
  Vector< int > vec2{nullptr, n2};
  List< Vector< int > >* list1 = nullptr;
  List< Vector< int > >* list2 = nullptr;
  try {
    vec1.data = new int[n1]{1, 2, 3, 4, 5};
    vec2.data = new int[n2]{10, 20, 30};
    list2 = new List< Vector< int > >{vec2, nullptr};
    list1 = new List< Vector< int > >{vec1, list2};
  } catch (...) {
    delete[] vec1.data;
    delete[] vec2.data;
    delete list1;
    delete list2;
    throw;
  }

  auto iter = begin(list1);
  std::cout << iter.curr->val.data[iter.i] << '\n';
  while (hasNext(iter)) {
    iter = next(iter);
    std::cout << iter.curr->val.data[iter.i] << '\n';
  }

  delete[] vec1.data;
  delete[] vec2.data;
  delete list1;
  delete list2;
}

