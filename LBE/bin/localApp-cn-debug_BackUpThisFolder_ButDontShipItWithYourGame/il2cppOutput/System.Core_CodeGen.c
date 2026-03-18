#include "pch-c.h"
#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include "codegen/il2cpp-codegen-metadata.h"





// 0x00000001 System.String SR::Format(System.String,System.Object)
extern void SR_Format_m7198B645F5C0A5E33F30AEF003C1F1D1415A9F86 (void);
// 0x00000002 System.Exception System.Linq.Error::ArgumentNull(System.String)
extern void Error_ArgumentNull_m1141D2C9AF8AB6ACC45E7488789598C5283D4EEE (void);
// 0x00000003 System.Exception System.Linq.Error::MoreThanOneMatch()
extern void Error_MoreThanOneMatch_mE8ABBCC1C5FBA4D7BBE5B0647992D20F005F7A97 (void);
// 0x00000004 System.Exception System.Linq.Error::NoElements()
extern void Error_NoElements_m49C996124733B026EA2FDBE9382AAD136CA22362 (void);
// 0x00000005 System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable::Where(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Boolean>)
// 0x00000006 System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable::Select(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,TResult>)
// 0x00000007 System.Func`2<TSource,System.Boolean> System.Linq.Enumerable::CombinePredicates(System.Func`2<TSource,System.Boolean>,System.Func`2<TSource,System.Boolean>)
// 0x00000008 System.Func`2<TSource,TResult> System.Linq.Enumerable::CombineSelectors(System.Func`2<TSource,TMiddle>,System.Func`2<TMiddle,TResult>)
// 0x00000009 System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable::SelectMany(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Collections.Generic.IEnumerable`1<TResult>>)
// 0x0000000A System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable::SelectManyIterator(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Collections.Generic.IEnumerable`1<TResult>>)
// 0x0000000B System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable::Take(System.Collections.Generic.IEnumerable`1<TSource>,System.Int32)
// 0x0000000C System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable::TakeIterator(System.Collections.Generic.IEnumerable`1<TSource>,System.Int32)
// 0x0000000D System.Linq.IOrderedEnumerable`1<TSource> System.Linq.Enumerable::OrderBy(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,TKey>)
// 0x0000000E System.Linq.IOrderedEnumerable`1<TSource> System.Linq.Enumerable::ThenBy(System.Linq.IOrderedEnumerable`1<TSource>,System.Func`2<TSource,TKey>)
// 0x0000000F System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable::Distinct(System.Collections.Generic.IEnumerable`1<TSource>)
// 0x00000010 System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable::DistinctIterator(System.Collections.Generic.IEnumerable`1<TSource>,System.Collections.Generic.IEqualityComparer`1<TSource>)
// 0x00000011 System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable::Except(System.Collections.Generic.IEnumerable`1<TSource>,System.Collections.Generic.IEnumerable`1<TSource>)
// 0x00000012 System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable::ExceptIterator(System.Collections.Generic.IEnumerable`1<TSource>,System.Collections.Generic.IEnumerable`1<TSource>,System.Collections.Generic.IEqualityComparer`1<TSource>)
// 0x00000013 TSource[] System.Linq.Enumerable::ToArray(System.Collections.Generic.IEnumerable`1<TSource>)
// 0x00000014 System.Collections.Generic.List`1<TSource> System.Linq.Enumerable::ToList(System.Collections.Generic.IEnumerable`1<TSource>)
// 0x00000015 System.Collections.Generic.Dictionary`2<TKey,TElement> System.Linq.Enumerable::ToDictionary(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,TKey>,System.Func`2<TSource,TElement>)
// 0x00000016 System.Collections.Generic.Dictionary`2<TKey,TElement> System.Linq.Enumerable::ToDictionary(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,TKey>,System.Func`2<TSource,TElement>,System.Collections.Generic.IEqualityComparer`1<TKey>)
// 0x00000017 TSource System.Linq.Enumerable::First(System.Collections.Generic.IEnumerable`1<TSource>)
// 0x00000018 TSource System.Linq.Enumerable::FirstOrDefault(System.Collections.Generic.IEnumerable`1<TSource>)
// 0x00000019 TSource System.Linq.Enumerable::FirstOrDefault(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Boolean>)
// 0x0000001A TSource System.Linq.Enumerable::Last(System.Collections.Generic.IEnumerable`1<TSource>)
// 0x0000001B TSource System.Linq.Enumerable::LastOrDefault(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Boolean>)
// 0x0000001C TSource System.Linq.Enumerable::SingleOrDefault(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Boolean>)
// 0x0000001D System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable::Empty()
// 0x0000001E System.Boolean System.Linq.Enumerable::Any(System.Collections.Generic.IEnumerable`1<TSource>)
// 0x0000001F System.Boolean System.Linq.Enumerable::Any(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Boolean>)
// 0x00000020 System.Boolean System.Linq.Enumerable::All(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Boolean>)
// 0x00000021 System.Int32 System.Linq.Enumerable::Count(System.Collections.Generic.IEnumerable`1<TSource>)
// 0x00000022 System.Int32 System.Linq.Enumerable::Count(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Boolean>)
// 0x00000023 System.Boolean System.Linq.Enumerable::Contains(System.Collections.Generic.IEnumerable`1<TSource>,TSource)
// 0x00000024 System.Boolean System.Linq.Enumerable::Contains(System.Collections.Generic.IEnumerable`1<TSource>,TSource,System.Collections.Generic.IEqualityComparer`1<TSource>)
// 0x00000025 System.Int32 System.Linq.Enumerable::Min(System.Collections.Generic.IEnumerable`1<System.Int32>)
extern void Enumerable_Min_m3D3C3E5CE25D27D94448CA832FB5AB9F702D5443 (void);
// 0x00000026 System.Int32 System.Linq.Enumerable::Max(System.Collections.Generic.IEnumerable`1<System.Int32>)
extern void Enumerable_Max_mF33848068459BE74BF534D16F6B678BB677EE704 (void);
// 0x00000027 System.Void System.Linq.Enumerable/Iterator`1::.ctor()
// 0x00000028 TSource System.Linq.Enumerable/Iterator`1::get_Current()
// 0x00000029 System.Linq.Enumerable/Iterator`1<TSource> System.Linq.Enumerable/Iterator`1::Clone()
// 0x0000002A System.Void System.Linq.Enumerable/Iterator`1::Dispose()
// 0x0000002B System.Collections.Generic.IEnumerator`1<TSource> System.Linq.Enumerable/Iterator`1::GetEnumerator()
// 0x0000002C System.Boolean System.Linq.Enumerable/Iterator`1::MoveNext()
// 0x0000002D System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable/Iterator`1::Select(System.Func`2<TSource,TResult>)
// 0x0000002E System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable/Iterator`1::Where(System.Func`2<TSource,System.Boolean>)
// 0x0000002F System.Object System.Linq.Enumerable/Iterator`1::System.Collections.IEnumerator.get_Current()
// 0x00000030 System.Collections.IEnumerator System.Linq.Enumerable/Iterator`1::System.Collections.IEnumerable.GetEnumerator()
// 0x00000031 System.Void System.Linq.Enumerable/Iterator`1::System.Collections.IEnumerator.Reset()
// 0x00000032 System.Void System.Linq.Enumerable/WhereEnumerableIterator`1::.ctor(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Boolean>)
// 0x00000033 System.Linq.Enumerable/Iterator`1<TSource> System.Linq.Enumerable/WhereEnumerableIterator`1::Clone()
// 0x00000034 System.Void System.Linq.Enumerable/WhereEnumerableIterator`1::Dispose()
// 0x00000035 System.Boolean System.Linq.Enumerable/WhereEnumerableIterator`1::MoveNext()
// 0x00000036 System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable/WhereEnumerableIterator`1::Select(System.Func`2<TSource,TResult>)
// 0x00000037 System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable/WhereEnumerableIterator`1::Where(System.Func`2<TSource,System.Boolean>)
// 0x00000038 System.Void System.Linq.Enumerable/WhereArrayIterator`1::.ctor(TSource[],System.Func`2<TSource,System.Boolean>)
// 0x00000039 System.Linq.Enumerable/Iterator`1<TSource> System.Linq.Enumerable/WhereArrayIterator`1::Clone()
// 0x0000003A System.Boolean System.Linq.Enumerable/WhereArrayIterator`1::MoveNext()
// 0x0000003B System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable/WhereArrayIterator`1::Select(System.Func`2<TSource,TResult>)
// 0x0000003C System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable/WhereArrayIterator`1::Where(System.Func`2<TSource,System.Boolean>)
// 0x0000003D System.Void System.Linq.Enumerable/WhereListIterator`1::.ctor(System.Collections.Generic.List`1<TSource>,System.Func`2<TSource,System.Boolean>)
// 0x0000003E System.Linq.Enumerable/Iterator`1<TSource> System.Linq.Enumerable/WhereListIterator`1::Clone()
// 0x0000003F System.Boolean System.Linq.Enumerable/WhereListIterator`1::MoveNext()
// 0x00000040 System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable/WhereListIterator`1::Select(System.Func`2<TSource,TResult>)
// 0x00000041 System.Collections.Generic.IEnumerable`1<TSource> System.Linq.Enumerable/WhereListIterator`1::Where(System.Func`2<TSource,System.Boolean>)
// 0x00000042 System.Void System.Linq.Enumerable/WhereSelectEnumerableIterator`2::.ctor(System.Collections.Generic.IEnumerable`1<TSource>,System.Func`2<TSource,System.Boolean>,System.Func`2<TSource,TResult>)
// 0x00000043 System.Linq.Enumerable/Iterator`1<TResult> System.Linq.Enumerable/WhereSelectEnumerableIterator`2::Clone()
// 0x00000044 System.Void System.Linq.Enumerable/WhereSelectEnumerableIterator`2::Dispose()
// 0x00000045 System.Boolean System.Linq.Enumerable/WhereSelectEnumerableIterator`2::MoveNext()
// 0x00000046 System.Collections.Generic.IEnumerable`1<TResult2> System.Linq.Enumerable/WhereSelectEnumerableIterator`2::Select(System.Func`2<TResult,TResult2>)
// 0x00000047 System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable/WhereSelectEnumerableIterator`2::Where(System.Func`2<TResult,System.Boolean>)
// 0x00000048 System.Void System.Linq.Enumerable/WhereSelectArrayIterator`2::.ctor(TSource[],System.Func`2<TSource,System.Boolean>,System.Func`2<TSource,TResult>)
// 0x00000049 System.Linq.Enumerable/Iterator`1<TResult> System.Linq.Enumerable/WhereSelectArrayIterator`2::Clone()
// 0x0000004A System.Boolean System.Linq.Enumerable/WhereSelectArrayIterator`2::MoveNext()
// 0x0000004B System.Collections.Generic.IEnumerable`1<TResult2> System.Linq.Enumerable/WhereSelectArrayIterator`2::Select(System.Func`2<TResult,TResult2>)
// 0x0000004C System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable/WhereSelectArrayIterator`2::Where(System.Func`2<TResult,System.Boolean>)
// 0x0000004D System.Void System.Linq.Enumerable/WhereSelectListIterator`2::.ctor(System.Collections.Generic.List`1<TSource>,System.Func`2<TSource,System.Boolean>,System.Func`2<TSource,TResult>)
// 0x0000004E System.Linq.Enumerable/Iterator`1<TResult> System.Linq.Enumerable/WhereSelectListIterator`2::Clone()
// 0x0000004F System.Boolean System.Linq.Enumerable/WhereSelectListIterator`2::MoveNext()
// 0x00000050 System.Collections.Generic.IEnumerable`1<TResult2> System.Linq.Enumerable/WhereSelectListIterator`2::Select(System.Func`2<TResult,TResult2>)
// 0x00000051 System.Collections.Generic.IEnumerable`1<TResult> System.Linq.Enumerable/WhereSelectListIterator`2::Where(System.Func`2<TResult,System.Boolean>)
// 0x00000052 System.Void System.Linq.Enumerable/<>c__DisplayClass6_0`1::.ctor()
// 0x00000053 System.Boolean System.Linq.Enumerable/<>c__DisplayClass6_0`1::<CombinePredicates>b__0(TSource)
// 0x00000054 System.Void System.Linq.Enumerable/<>c__DisplayClass7_0`3::.ctor()
// 0x00000055 TResult System.Linq.Enumerable/<>c__DisplayClass7_0`3::<CombineSelectors>b__0(TSource)
// 0x00000056 System.Void System.Linq.Enumerable/<SelectManyIterator>d__17`2::.ctor(System.Int32)
// 0x00000057 System.Void System.Linq.Enumerable/<SelectManyIterator>d__17`2::System.IDisposable.Dispose()
// 0x00000058 System.Boolean System.Linq.Enumerable/<SelectManyIterator>d__17`2::MoveNext()
// 0x00000059 System.Void System.Linq.Enumerable/<SelectManyIterator>d__17`2::<>m__Finally1()
// 0x0000005A System.Void System.Linq.Enumerable/<SelectManyIterator>d__17`2::<>m__Finally2()
// 0x0000005B TResult System.Linq.Enumerable/<SelectManyIterator>d__17`2::System.Collections.Generic.IEnumerator<TResult>.get_Current()
// 0x0000005C System.Void System.Linq.Enumerable/<SelectManyIterator>d__17`2::System.Collections.IEnumerator.Reset()
// 0x0000005D System.Object System.Linq.Enumerable/<SelectManyIterator>d__17`2::System.Collections.IEnumerator.get_Current()
// 0x0000005E System.Collections.Generic.IEnumerator`1<TResult> System.Linq.Enumerable/<SelectManyIterator>d__17`2::System.Collections.Generic.IEnumerable<TResult>.GetEnumerator()
// 0x0000005F System.Collections.IEnumerator System.Linq.Enumerable/<SelectManyIterator>d__17`2::System.Collections.IEnumerable.GetEnumerator()
// 0x00000060 System.Void System.Linq.Enumerable/<TakeIterator>d__25`1::.ctor(System.Int32)
// 0x00000061 System.Void System.Linq.Enumerable/<TakeIterator>d__25`1::System.IDisposable.Dispose()
// 0x00000062 System.Boolean System.Linq.Enumerable/<TakeIterator>d__25`1::MoveNext()
// 0x00000063 System.Void System.Linq.Enumerable/<TakeIterator>d__25`1::<>m__Finally1()
// 0x00000064 TSource System.Linq.Enumerable/<TakeIterator>d__25`1::System.Collections.Generic.IEnumerator<TSource>.get_Current()
// 0x00000065 System.Void System.Linq.Enumerable/<TakeIterator>d__25`1::System.Collections.IEnumerator.Reset()
// 0x00000066 System.Object System.Linq.Enumerable/<TakeIterator>d__25`1::System.Collections.IEnumerator.get_Current()
// 0x00000067 System.Collections.Generic.IEnumerator`1<TSource> System.Linq.Enumerable/<TakeIterator>d__25`1::System.Collections.Generic.IEnumerable<TSource>.GetEnumerator()
// 0x00000068 System.Collections.IEnumerator System.Linq.Enumerable/<TakeIterator>d__25`1::System.Collections.IEnumerable.GetEnumerator()
// 0x00000069 System.Void System.Linq.Enumerable/<DistinctIterator>d__68`1::.ctor(System.Int32)
// 0x0000006A System.Void System.Linq.Enumerable/<DistinctIterator>d__68`1::System.IDisposable.Dispose()
// 0x0000006B System.Boolean System.Linq.Enumerable/<DistinctIterator>d__68`1::MoveNext()
// 0x0000006C System.Void System.Linq.Enumerable/<DistinctIterator>d__68`1::<>m__Finally1()
// 0x0000006D TSource System.Linq.Enumerable/<DistinctIterator>d__68`1::System.Collections.Generic.IEnumerator<TSource>.get_Current()
// 0x0000006E System.Void System.Linq.Enumerable/<DistinctIterator>d__68`1::System.Collections.IEnumerator.Reset()
// 0x0000006F System.Object System.Linq.Enumerable/<DistinctIterator>d__68`1::System.Collections.IEnumerator.get_Current()
// 0x00000070 System.Collections.Generic.IEnumerator`1<TSource> System.Linq.Enumerable/<DistinctIterator>d__68`1::System.Collections.Generic.IEnumerable<TSource>.GetEnumerator()
// 0x00000071 System.Collections.IEnumerator System.Linq.Enumerable/<DistinctIterator>d__68`1::System.Collections.IEnumerable.GetEnumerator()
// 0x00000072 System.Void System.Linq.Enumerable/<ExceptIterator>d__77`1::.ctor(System.Int32)
// 0x00000073 System.Void System.Linq.Enumerable/<ExceptIterator>d__77`1::System.IDisposable.Dispose()
// 0x00000074 System.Boolean System.Linq.Enumerable/<ExceptIterator>d__77`1::MoveNext()
// 0x00000075 System.Void System.Linq.Enumerable/<ExceptIterator>d__77`1::<>m__Finally1()
// 0x00000076 TSource System.Linq.Enumerable/<ExceptIterator>d__77`1::System.Collections.Generic.IEnumerator<TSource>.get_Current()
// 0x00000077 System.Void System.Linq.Enumerable/<ExceptIterator>d__77`1::System.Collections.IEnumerator.Reset()
// 0x00000078 System.Object System.Linq.Enumerable/<ExceptIterator>d__77`1::System.Collections.IEnumerator.get_Current()
// 0x00000079 System.Collections.Generic.IEnumerator`1<TSource> System.Linq.Enumerable/<ExceptIterator>d__77`1::System.Collections.Generic.IEnumerable<TSource>.GetEnumerator()
// 0x0000007A System.Collections.IEnumerator System.Linq.Enumerable/<ExceptIterator>d__77`1::System.Collections.IEnumerable.GetEnumerator()
// 0x0000007B System.Void System.Linq.EmptyEnumerable`1::.cctor()
// 0x0000007C System.Linq.IOrderedEnumerable`1<TElement> System.Linq.IOrderedEnumerable`1::CreateOrderedEnumerable(System.Func`2<TElement,TKey>,System.Collections.Generic.IComparer`1<TKey>,System.Boolean)
// 0x0000007D System.Void System.Linq.Set`1::.ctor(System.Collections.Generic.IEqualityComparer`1<TElement>)
// 0x0000007E System.Boolean System.Linq.Set`1::Add(TElement)
// 0x0000007F System.Boolean System.Linq.Set`1::Find(TElement,System.Boolean)
// 0x00000080 System.Void System.Linq.Set`1::Resize()
// 0x00000081 System.Int32 System.Linq.Set`1::InternalGetHashCode(TElement)
// 0x00000082 System.Collections.Generic.IEnumerator`1<TElement> System.Linq.OrderedEnumerable`1::GetEnumerator()
// 0x00000083 System.Linq.EnumerableSorter`1<TElement> System.Linq.OrderedEnumerable`1::GetEnumerableSorter(System.Linq.EnumerableSorter`1<TElement>)
// 0x00000084 System.Collections.IEnumerator System.Linq.OrderedEnumerable`1::System.Collections.IEnumerable.GetEnumerator()
// 0x00000085 System.Linq.IOrderedEnumerable`1<TElement> System.Linq.OrderedEnumerable`1::System.Linq.IOrderedEnumerable<TElement>.CreateOrderedEnumerable(System.Func`2<TElement,TKey>,System.Collections.Generic.IComparer`1<TKey>,System.Boolean)
// 0x00000086 System.Void System.Linq.OrderedEnumerable`1::.ctor()
// 0x00000087 System.Void System.Linq.OrderedEnumerable`1/<GetEnumerator>d__1::.ctor(System.Int32)
// 0x00000088 System.Void System.Linq.OrderedEnumerable`1/<GetEnumerator>d__1::System.IDisposable.Dispose()
// 0x00000089 System.Boolean System.Linq.OrderedEnumerable`1/<GetEnumerator>d__1::MoveNext()
// 0x0000008A TElement System.Linq.OrderedEnumerable`1/<GetEnumerator>d__1::System.Collections.Generic.IEnumerator<TElement>.get_Current()
// 0x0000008B System.Void System.Linq.OrderedEnumerable`1/<GetEnumerator>d__1::System.Collections.IEnumerator.Reset()
// 0x0000008C System.Object System.Linq.OrderedEnumerable`1/<GetEnumerator>d__1::System.Collections.IEnumerator.get_Current()
// 0x0000008D System.Void System.Linq.OrderedEnumerable`2::.ctor(System.Collections.Generic.IEnumerable`1<TElement>,System.Func`2<TElement,TKey>,System.Collections.Generic.IComparer`1<TKey>,System.Boolean)
// 0x0000008E System.Linq.EnumerableSorter`1<TElement> System.Linq.OrderedEnumerable`2::GetEnumerableSorter(System.Linq.EnumerableSorter`1<TElement>)
// 0x0000008F System.Void System.Linq.EnumerableSorter`1::ComputeKeys(TElement[],System.Int32)
// 0x00000090 System.Int32 System.Linq.EnumerableSorter`1::CompareKeys(System.Int32,System.Int32)
// 0x00000091 System.Int32[] System.Linq.EnumerableSorter`1::Sort(TElement[],System.Int32)
// 0x00000092 System.Void System.Linq.EnumerableSorter`1::QuickSort(System.Int32[],System.Int32,System.Int32)
// 0x00000093 System.Void System.Linq.EnumerableSorter`1::.ctor()
// 0x00000094 System.Void System.Linq.EnumerableSorter`2::.ctor(System.Func`2<TElement,TKey>,System.Collections.Generic.IComparer`1<TKey>,System.Boolean,System.Linq.EnumerableSorter`1<TElement>)
// 0x00000095 System.Void System.Linq.EnumerableSorter`2::ComputeKeys(TElement[],System.Int32)
// 0x00000096 System.Int32 System.Linq.EnumerableSorter`2::CompareKeys(System.Int32,System.Int32)
// 0x00000097 System.Void System.Linq.Buffer`1::.ctor(System.Collections.Generic.IEnumerable`1<TElement>)
// 0x00000098 TElement[] System.Linq.Buffer`1::ToArray()
// 0x00000099 System.Linq.Expressions.ExpressionType System.Linq.Expressions.Expression::get_NodeType()
extern void Expression_get_NodeType_m86A459B820D793551B0728F93F345B1B1241184F (void);
// 0x0000009A System.Type System.Linq.Expressions.Expression::get_Type()
extern void Expression_get_Type_m4AC9DBEF56D88946B63069DEB3BE1B7C3B5EAF06 (void);
// 0x0000009B System.Boolean System.Linq.Expressions.Expression::get_CanReduce()
extern void Expression_get_CanReduce_m30EE3C351EA9FC2CC69587517388669524078688 (void);
// 0x0000009C System.Linq.Expressions.Expression System.Linq.Expressions.Expression::Reduce()
extern void Expression_Reduce_mC29568DCEEDB09AF835AA0339448DE3502333D01 (void);
// 0x0000009D System.Linq.Expressions.Expression System.Linq.Expressions.Expression::VisitChildren(System.Linq.Expressions.ExpressionVisitor)
extern void Expression_VisitChildren_m06C46AA86F547C59012080E420831412F0FEA9AC (void);
// 0x0000009E System.Linq.Expressions.Expression System.Linq.Expressions.Expression::Accept(System.Linq.Expressions.ExpressionVisitor)
extern void Expression_Accept_mFB922854EC333F269F5994CE65B86A30189E0F65 (void);
// 0x0000009F System.Linq.Expressions.Expression System.Linq.Expressions.Expression::ReduceAndCheck()
extern void Expression_ReduceAndCheck_m8CF664E3CC592955516A833A9AF4A42278AF46C0 (void);
// 0x000000A0 System.String System.Linq.Expressions.Expression::get_DebugView()
extern void Expression_get_DebugView_mE3D40DC10A0290401CADA46440DBCE8521048D92 (void);
// 0x000000A1 System.Void System.Linq.Expressions.Expression::.cctor()
extern void Expression__cctor_mE34384A199AAD190A67CF73E7F9806FC3B8CA754 (void);
// 0x000000A2 System.Void System.Linq.Expressions.Expression/LambdaExpressionProxy::.ctor(System.Linq.Expressions.LambdaExpression)
extern void LambdaExpressionProxy__ctor_m853CB81D9E6F6492B6726A8B7CA421A857F3DBF8 (void);
// 0x000000A3 System.Linq.Expressions.Expression System.Linq.Expressions.Expression/LambdaExpressionProxy::get_Body()
extern void LambdaExpressionProxy_get_Body_mEEB6B316074140914C3A928392AEED75E3859F6F (void);
// 0x000000A4 System.Boolean System.Linq.Expressions.Expression/LambdaExpressionProxy::get_CanReduce()
extern void LambdaExpressionProxy_get_CanReduce_mF2A55247DA047343B063DE7CD9A7EC9F91C9A2A6 (void);
// 0x000000A5 System.String System.Linq.Expressions.Expression/LambdaExpressionProxy::get_DebugView()
extern void LambdaExpressionProxy_get_DebugView_m1A2BFAE18A9B72415686F010A6E1B2341E386545 (void);
// 0x000000A6 System.String System.Linq.Expressions.Expression/LambdaExpressionProxy::get_Name()
extern void LambdaExpressionProxy_get_Name_m5EA9B36355FA2F5353686BA1261D5C12A5B1C5D8 (void);
// 0x000000A7 System.Linq.Expressions.ExpressionType System.Linq.Expressions.Expression/LambdaExpressionProxy::get_NodeType()
extern void LambdaExpressionProxy_get_NodeType_mB58407D2E69616F9FE1DE716BB16B1972FFF1657 (void);
// 0x000000A8 System.Collections.ObjectModel.ReadOnlyCollection`1<System.Linq.Expressions.ParameterExpression> System.Linq.Expressions.Expression/LambdaExpressionProxy::get_Parameters()
extern void LambdaExpressionProxy_get_Parameters_m359BEC19A66BB4CF0D3A7FF11A370C0D85B88E31 (void);
// 0x000000A9 System.Type System.Linq.Expressions.Expression/LambdaExpressionProxy::get_ReturnType()
extern void LambdaExpressionProxy_get_ReturnType_m97676A2B02AA0AA2AD179385D87AAF5483DC973D (void);
// 0x000000AA System.Boolean System.Linq.Expressions.Expression/LambdaExpressionProxy::get_TailCall()
extern void LambdaExpressionProxy_get_TailCall_mC77892AA06C0026967D925D92C476C47748F0CB8 (void);
// 0x000000AB System.Type System.Linq.Expressions.Expression/LambdaExpressionProxy::get_Type()
extern void LambdaExpressionProxy_get_Type_mCE70232EC775F8BA2843B4E17FA82139B8919CDB (void);
// 0x000000AC System.Void System.Linq.Expressions.Expression/MemberExpressionProxy::.ctor(System.Linq.Expressions.MemberExpression)
extern void MemberExpressionProxy__ctor_mC505DDCAFD0FAFE7B1115269A0EFDA56B28D1F9C (void);
// 0x000000AD System.Boolean System.Linq.Expressions.Expression/MemberExpressionProxy::get_CanReduce()
extern void MemberExpressionProxy_get_CanReduce_m17A87F8630972D0061E29C04A7EAEB6A0D79FBA3 (void);
// 0x000000AE System.String System.Linq.Expressions.Expression/MemberExpressionProxy::get_DebugView()
extern void MemberExpressionProxy_get_DebugView_m6CB9DAB1FB28080346B1AF731A6C9F0EAB132BD6 (void);
// 0x000000AF System.Linq.Expressions.Expression System.Linq.Expressions.Expression/MemberExpressionProxy::get_Expression()
extern void MemberExpressionProxy_get_Expression_m621D062B8613F0F302F61BB24F84D0EE6CF9271C (void);
// 0x000000B0 System.Reflection.MemberInfo System.Linq.Expressions.Expression/MemberExpressionProxy::get_Member()
extern void MemberExpressionProxy_get_Member_mEF38502CD36FF63495CCE4DD84ED96FAB216911A (void);
// 0x000000B1 System.Linq.Expressions.ExpressionType System.Linq.Expressions.Expression/MemberExpressionProxy::get_NodeType()
extern void MemberExpressionProxy_get_NodeType_mEA7E810ED6B75385171F436DD0640B88C101E922 (void);
// 0x000000B2 System.Type System.Linq.Expressions.Expression/MemberExpressionProxy::get_Type()
extern void MemberExpressionProxy_get_Type_mC3046CD402C885777AC01CDA6F395B74C49BAEAC (void);
// 0x000000B3 System.Void System.Linq.Expressions.Expression/ParameterExpressionProxy::.ctor(System.Linq.Expressions.ParameterExpression)
extern void ParameterExpressionProxy__ctor_m5B0728A97F390E91B95AAA208BF67E6635F3168F (void);
// 0x000000B4 System.Boolean System.Linq.Expressions.Expression/ParameterExpressionProxy::get_CanReduce()
extern void ParameterExpressionProxy_get_CanReduce_mD2773677857D9DE3ADBDD4BC75DE1615A49CB841 (void);
// 0x000000B5 System.String System.Linq.Expressions.Expression/ParameterExpressionProxy::get_DebugView()
extern void ParameterExpressionProxy_get_DebugView_m02E853F0E274A8BB71AA96D68D98FB9DDDC5DC7D (void);
// 0x000000B6 System.Boolean System.Linq.Expressions.Expression/ParameterExpressionProxy::get_IsByRef()
extern void ParameterExpressionProxy_get_IsByRef_mEDDDDE67041C802EC1021B2AB3D1F267F742A57E (void);
// 0x000000B7 System.String System.Linq.Expressions.Expression/ParameterExpressionProxy::get_Name()
extern void ParameterExpressionProxy_get_Name_m069CA1BE4083596E2F09703FF6CFCDB7C49ACF9E (void);
// 0x000000B8 System.Linq.Expressions.ExpressionType System.Linq.Expressions.Expression/ParameterExpressionProxy::get_NodeType()
extern void ParameterExpressionProxy_get_NodeType_mDDBBD7FEF560C6828F2D7EDFDB9D845BFFF6FB33 (void);
// 0x000000B9 System.Type System.Linq.Expressions.Expression/ParameterExpressionProxy::get_Type()
extern void ParameterExpressionProxy_get_Type_m0A29FD9A32EE5EB9DC4C6D14E7DF918AF151C279 (void);
// 0x000000BA System.Void System.Linq.Expressions.Expression/UnaryExpressionProxy::.ctor(System.Linq.Expressions.UnaryExpression)
extern void UnaryExpressionProxy__ctor_m808A75668E3F5C527AD3638EB6634E8F8EB3D495 (void);
// 0x000000BB System.Boolean System.Linq.Expressions.Expression/UnaryExpressionProxy::get_CanReduce()
extern void UnaryExpressionProxy_get_CanReduce_m99FD7F141DC656290A3D10FADFAFA7D26A6D4E64 (void);
// 0x000000BC System.String System.Linq.Expressions.Expression/UnaryExpressionProxy::get_DebugView()
extern void UnaryExpressionProxy_get_DebugView_m69448791B12B247D7CA5AFEC1C89B6F597ABC9D1 (void);
// 0x000000BD System.Boolean System.Linq.Expressions.Expression/UnaryExpressionProxy::get_IsLifted()
extern void UnaryExpressionProxy_get_IsLifted_m1451664C4E86501939C109FFE8011D7CB9F10099 (void);
// 0x000000BE System.Boolean System.Linq.Expressions.Expression/UnaryExpressionProxy::get_IsLiftedToNull()
extern void UnaryExpressionProxy_get_IsLiftedToNull_m1A6445847373D85512EAE96F0FD4D94AE2839E11 (void);
// 0x000000BF System.Reflection.MethodInfo System.Linq.Expressions.Expression/UnaryExpressionProxy::get_Method()
extern void UnaryExpressionProxy_get_Method_m022EBA7324513D794AFF7E2AF51142D951A14EE6 (void);
// 0x000000C0 System.Linq.Expressions.ExpressionType System.Linq.Expressions.Expression/UnaryExpressionProxy::get_NodeType()
extern void UnaryExpressionProxy_get_NodeType_m2996E8478351A94B92C9FA4CFB9DF756436D13B5 (void);
// 0x000000C1 System.Linq.Expressions.Expression System.Linq.Expressions.Expression/UnaryExpressionProxy::get_Operand()
extern void UnaryExpressionProxy_get_Operand_m1012230FA895135E9B50FBF54FD800CF17D49FB7 (void);
// 0x000000C2 System.Type System.Linq.Expressions.Expression/UnaryExpressionProxy::get_Type()
extern void UnaryExpressionProxy_get_Type_m536DC0A928B0F4C3D3EDAC5E203E25FBEEAB8AB1 (void);
// 0x000000C3 System.Void System.Linq.Expressions.DebugViewWriter::.ctor(System.IO.TextWriter)
extern void DebugViewWriter__ctor_m7F103C336119E054D04D04D2974EC2FC94BC4C2D (void);
// 0x000000C4 System.Int32 System.Linq.Expressions.DebugViewWriter::get_Base()
extern void DebugViewWriter_get_Base_m4B18E918536DC2C2C9777364A3D02A655D7D7625 (void);
// 0x000000C5 System.Int32 System.Linq.Expressions.DebugViewWriter::get_Delta()
extern void DebugViewWriter_get_Delta_m1D601E610796CF9861B231605DC41D5864BEBF4F (void);
// 0x000000C6 System.Int32 System.Linq.Expressions.DebugViewWriter::get_Depth()
extern void DebugViewWriter_get_Depth_m6EFA4F708BC2B32263E24AEED59B7E9F489574E2 (void);
// 0x000000C7 System.Void System.Linq.Expressions.DebugViewWriter::Indent()
extern void DebugViewWriter_Indent_mEAAF7F8119D723B4363486B39EC5EFF8357CA3C3 (void);
// 0x000000C8 System.Void System.Linq.Expressions.DebugViewWriter::Dedent()
extern void DebugViewWriter_Dedent_m32EEF64C20FEF360759C16BB3440A0F9E9E5A62C (void);
// 0x000000C9 System.Void System.Linq.Expressions.DebugViewWriter::NewLine()
extern void DebugViewWriter_NewLine_mC3DFE844CA2802D707700A17D0488AF5051C2E98 (void);
// 0x000000CA System.Int32 System.Linq.Expressions.DebugViewWriter::GetId(T,System.Collections.Generic.Dictionary`2<T,System.Int32>&)
// 0x000000CB System.Int32 System.Linq.Expressions.DebugViewWriter::GetLambdaId(System.Linq.Expressions.LambdaExpression)
extern void DebugViewWriter_GetLambdaId_mECC1286C8EECCB4D771239797B5E678DA5F506B1 (void);
// 0x000000CC System.Int32 System.Linq.Expressions.DebugViewWriter::GetParamId(System.Linq.Expressions.ParameterExpression)
extern void DebugViewWriter_GetParamId_m7EDDA26EC415F7327CDAA447D6701B29184C0429 (void);
// 0x000000CD System.Void System.Linq.Expressions.DebugViewWriter::WriteTo(System.Linq.Expressions.Expression,System.IO.TextWriter)
extern void DebugViewWriter_WriteTo_m74A8ACEE24D5C6425D528F0F1D4E70C57193BD3D (void);
// 0x000000CE System.Void System.Linq.Expressions.DebugViewWriter::WriteTo(System.Linq.Expressions.Expression)
extern void DebugViewWriter_WriteTo_m2F19CE592AD660AAF040AE83EE73E0DFE8BA47F9 (void);
// 0x000000CF System.Void System.Linq.Expressions.DebugViewWriter::Out(System.String)
extern void DebugViewWriter_Out_m015226FD79DC9842D02C8E6C2C9DD03E134D9A18 (void);
// 0x000000D0 System.Void System.Linq.Expressions.DebugViewWriter::Out(System.Linq.Expressions.DebugViewWriter/Flow,System.String)
extern void DebugViewWriter_Out_m059DB7930ACD59E21849BA341D4D251F4BE6FD8F (void);
// 0x000000D1 System.Void System.Linq.Expressions.DebugViewWriter::Out(System.String,System.Linq.Expressions.DebugViewWriter/Flow)
extern void DebugViewWriter_Out_mDF85CA38ABF60A7EE3853A409B6391E0AF26168C (void);
// 0x000000D2 System.Void System.Linq.Expressions.DebugViewWriter::Out(System.Linq.Expressions.DebugViewWriter/Flow,System.String,System.Linq.Expressions.DebugViewWriter/Flow)
extern void DebugViewWriter_Out_m5C225831A3A1ABF3C48F2CED090D66B25B9411D8 (void);
// 0x000000D3 System.Void System.Linq.Expressions.DebugViewWriter::WriteLine()
extern void DebugViewWriter_WriteLine_mAD23CC084D2310A35BB26FF1921CA61A9C0224F8 (void);
// 0x000000D4 System.Void System.Linq.Expressions.DebugViewWriter::Write(System.String)
extern void DebugViewWriter_Write_m3E7ACA1062A8C9466A1E9939A3CA6074787EC6B3 (void);
// 0x000000D5 System.Linq.Expressions.DebugViewWriter/Flow System.Linq.Expressions.DebugViewWriter::GetFlow(System.Linq.Expressions.DebugViewWriter/Flow)
extern void DebugViewWriter_GetFlow_m5307C3DBBAD119486501B7C6A3A8B5C69BEE878B (void);
// 0x000000D6 System.Linq.Expressions.DebugViewWriter/Flow System.Linq.Expressions.DebugViewWriter::CheckBreak(System.Linq.Expressions.DebugViewWriter/Flow)
extern void DebugViewWriter_CheckBreak_mB788A594EE2531CC5BBC3676CB9AB54D5D440E5C (void);
// 0x000000D7 System.Void System.Linq.Expressions.DebugViewWriter::VisitDeclarations(System.Collections.Generic.IReadOnlyList`1<System.Linq.Expressions.ParameterExpression>)
extern void DebugViewWriter_VisitDeclarations_m667EF88D9F3B2A3D04E04933E3B5E77E80A7144A (void);
// 0x000000D8 System.Void System.Linq.Expressions.DebugViewWriter::VisitExpressions(System.Char,System.Char,System.Collections.Generic.IReadOnlyList`1<T>,System.Action`1<T>)
// 0x000000D9 System.Linq.Expressions.Expression System.Linq.Expressions.DebugViewWriter::VisitParameter(System.Linq.Expressions.ParameterExpression)
extern void DebugViewWriter_VisitParameter_m6B5BDB5A5411936A8E29F70D402635686E3B5E27 (void);
// 0x000000DA System.Linq.Expressions.Expression System.Linq.Expressions.DebugViewWriter::VisitExtension(System.Linq.Expressions.Expression)
extern void DebugViewWriter_VisitExtension_mEBBED9DCECCED1EA1DC2DC5EE1B25341E005C3AA (void);
// 0x000000DB System.Void System.Linq.Expressions.DebugViewWriter::WriteLambda(System.Linq.Expressions.LambdaExpression)
extern void DebugViewWriter_WriteLambda_mA319115AC57D05C6B2A875F88F71DD6AC98A27B2 (void);
// 0x000000DC System.String System.Linq.Expressions.DebugViewWriter::GetLambdaName(System.Linq.Expressions.LambdaExpression)
extern void DebugViewWriter_GetLambdaName_m080552587E1A86C78B612178334641B12CDA57D4 (void);
// 0x000000DD System.Boolean System.Linq.Expressions.DebugViewWriter::ContainsWhiteSpace(System.String)
extern void DebugViewWriter_ContainsWhiteSpace_mF9D69062D6A1E7E604F78AD0F9146CCC763C26DF (void);
// 0x000000DE System.String System.Linq.Expressions.DebugViewWriter::QuoteName(System.String)
extern void DebugViewWriter_QuoteName_mCE3A53E4D1F177BA67846D19C4EDF063B534F493 (void);
// 0x000000DF System.String System.Linq.Expressions.DebugViewWriter::GetDisplayName(System.String)
extern void DebugViewWriter_GetDisplayName_m680F00E5FF2145619CB898F80E22135AE59619EA (void);
// 0x000000E0 System.Void System.Linq.Expressions.DebugViewWriter::<VisitDeclarations>b__38_0(System.Linq.Expressions.ParameterExpression)
extern void DebugViewWriter_U3CVisitDeclarationsU3Eb__38_0_m638E405BD92F9E070928D5E8253C862CB0368A0F (void);
// 0x000000E1 System.Exception System.Linq.Expressions.Error::ReducibleMustOverrideReduce()
extern void Error_ReducibleMustOverrideReduce_m369D2EDF8DD292F0CEBAE0991AF5C9F1CA276DD6 (void);
// 0x000000E2 System.Exception System.Linq.Expressions.Error::MustReduceToDifferent()
extern void Error_MustReduceToDifferent_m36A8F6F0A3AE082814045AF5125981212C36D38B (void);
// 0x000000E3 System.Exception System.Linq.Expressions.Error::ReducedNotCompatible()
extern void Error_ReducedNotCompatible_m597288FC7F20F76ED7EE7A79157914643C661FFE (void);
// 0x000000E4 System.Exception System.Linq.Expressions.Error::MustBeReducible()
extern void Error_MustBeReducible_mED85C31673392919ACFE804F81190778783975A7 (void);
// 0x000000E5 System.Exception System.Linq.Expressions.Error::ExtensionNodeMustOverrideProperty(System.Object)
extern void Error_ExtensionNodeMustOverrideProperty_mD5BBC9AEE0B7601E3814C967A521A87A5713EB39 (void);
// 0x000000E6 System.Void System.Linq.Expressions.ExpressionVisitor::.ctor()
extern void ExpressionVisitor__ctor_m2974B344C35DD823BDA6D6313DAE4C7F64541393 (void);
// 0x000000E7 System.Linq.Expressions.Expression System.Linq.Expressions.ExpressionVisitor::Visit(System.Linq.Expressions.Expression)
extern void ExpressionVisitor_Visit_mCC12DFA654B568E00CA4FD5A38C284FDF542FA6D (void);
// 0x000000E8 System.Linq.Expressions.Expression System.Linq.Expressions.ExpressionVisitor::VisitExtension(System.Linq.Expressions.Expression)
extern void ExpressionVisitor_VisitExtension_m16258F15F7B3BE8BAE1BB3090AC741E471F46F2D (void);
// 0x000000E9 System.Linq.Expressions.Expression System.Linq.Expressions.ExpressionVisitor::VisitParameter(System.Linq.Expressions.ParameterExpression)
extern void ExpressionVisitor_VisitParameter_m66B44224F5F0ACF016A5C1652CD09B9AEA9AFC14 (void);
// 0x000000EA System.Collections.ObjectModel.ReadOnlyCollection`1<System.Linq.Expressions.ParameterExpression> System.Linq.Expressions.LambdaExpression::get_Parameters()
extern void LambdaExpression_get_Parameters_m60512B6B3670A57CD4789335522EB4CAEF59A05F (void);
// 0x000000EB System.String System.Linq.Expressions.LambdaExpression::get_Name()
extern void LambdaExpression_get_Name_mC099AAE16A8765B43A0D835C6AB33DFA80D4F878 (void);
// 0x000000EC System.String System.Linq.Expressions.LambdaExpression::get_NameCore()
extern void LambdaExpression_get_NameCore_m9CE950CD0859EA1BAA728850D353EF2292D5037C (void);
// 0x000000ED System.Linq.Expressions.Expression System.Linq.Expressions.LambdaExpression::get_Body()
extern void LambdaExpression_get_Body_m161E156442547AE8A6837C5AE065BD93345451DE (void);
// 0x000000EE System.Type System.Linq.Expressions.LambdaExpression::get_ReturnType()
extern void LambdaExpression_get_ReturnType_mA8E8D3FF1557408AFB1CE8C1B7ED879F045D41FB (void);
// 0x000000EF System.Boolean System.Linq.Expressions.LambdaExpression::get_TailCall()
extern void LambdaExpression_get_TailCall_m5C8FF396DC74BF7D57D40A22040CF500FABAE2E5 (void);
// 0x000000F0 System.Boolean System.Linq.Expressions.LambdaExpression::get_TailCallCore()
extern void LambdaExpression_get_TailCallCore_m76CF7B1A957240BC996993CD94E34FB49634CCCC (void);
// 0x000000F1 System.Collections.ObjectModel.ReadOnlyCollection`1<System.Linq.Expressions.ParameterExpression> System.Linq.Expressions.LambdaExpression::GetOrMakeParameters()
extern void LambdaExpression_GetOrMakeParameters_m2627C12ACFCE4104415D9B9661BC5D4EF4521A7A (void);
// 0x000000F2 System.Reflection.MemberInfo System.Linq.Expressions.MemberExpression::get_Member()
extern void MemberExpression_get_Member_m30A7DCC7673A38BE9F06597DC9F5305E61B88104 (void);
// 0x000000F3 System.Linq.Expressions.Expression System.Linq.Expressions.MemberExpression::get_Expression()
extern void MemberExpression_get_Expression_mF422466944A9875383573A4FD01CD661C64B7503 (void);
// 0x000000F4 System.Reflection.MemberInfo System.Linq.Expressions.MemberExpression::GetMember()
extern void MemberExpression_GetMember_mB44F09D4104C91F27C0F3246C222224728A9C3FC (void);
// 0x000000F5 System.String System.Linq.Expressions.ParameterExpression::get_Name()
extern void ParameterExpression_get_Name_m5F48CE2BAC279432E92DC3AFBF627F234D0E1D2A (void);
// 0x000000F6 System.Boolean System.Linq.Expressions.ParameterExpression::get_IsByRef()
extern void ParameterExpression_get_IsByRef_m01BDD008CE1E89DE90DA5D35E951949CC665FE1C (void);
// 0x000000F7 System.Boolean System.Linq.Expressions.ParameterExpression::GetIsByRef()
extern void ParameterExpression_GetIsByRef_m8F08D04AA3BDD969B05F5B95101D5576DD59E4D6 (void);
// 0x000000F8 System.String System.Linq.Expressions.Strings::get_ReducibleMustOverrideReduce()
extern void Strings_get_ReducibleMustOverrideReduce_m3A42A36C78DEE542AE7861CCE517D5B05AD822B1 (void);
// 0x000000F9 System.String System.Linq.Expressions.Strings::get_MustReduceToDifferent()
extern void Strings_get_MustReduceToDifferent_m958D994C04C8CB086B7C38E609E24FFC47E5265B (void);
// 0x000000FA System.String System.Linq.Expressions.Strings::get_ReducedNotCompatible()
extern void Strings_get_ReducedNotCompatible_mDE70EE4B9AD1B81B7341E17740056421BF7ECD7D (void);
// 0x000000FB System.String System.Linq.Expressions.Strings::get_MustBeReducible()
extern void Strings_get_MustBeReducible_m6AA622B4FC648A5A1B05D4CC21B9EB4A77600B79 (void);
// 0x000000FC System.String System.Linq.Expressions.Strings::ExtensionNodeMustOverrideProperty(System.Object)
extern void Strings_ExtensionNodeMustOverrideProperty_m9104CAA7D2A9E08CBB135788A14930D2B9720284 (void);
// 0x000000FD System.Linq.Expressions.Expression System.Linq.Expressions.UnaryExpression::get_Operand()
extern void UnaryExpression_get_Operand_mE144387E98BABF0D3FD8E4640612A726D91E2943 (void);
// 0x000000FE System.Reflection.MethodInfo System.Linq.Expressions.UnaryExpression::get_Method()
extern void UnaryExpression_get_Method_mA8D37E71BEA657B6999A51277A7D7CBDF951E265 (void);
// 0x000000FF System.Boolean System.Linq.Expressions.UnaryExpression::get_IsLifted()
extern void UnaryExpression_get_IsLifted_m06A58D1977585CE5EFC1FEB58128DF06A5F8C626 (void);
// 0x00000100 System.Boolean System.Linq.Expressions.UnaryExpression::get_IsLiftedToNull()
extern void UnaryExpression_get_IsLiftedToNull_m6A6103EBBB80AB1A349197D7E562B2B4898AC38E (void);
// 0x00000101 System.Void System.Dynamic.Utils.CacheDict`2::.ctor(System.Int32)
// 0x00000102 System.Int32 System.Dynamic.Utils.CacheDict`2::AlignSize(System.Int32)
// 0x00000103 System.Boolean System.Dynamic.Utils.CacheDict`2::TryGetValue(TKey,TValue&)
// 0x00000104 System.Void System.Dynamic.Utils.CacheDict`2::Add(TKey,TValue)
// 0x00000105 System.Void System.Dynamic.Utils.CacheDict`2::set_Item(TKey,TValue)
// 0x00000106 System.Void System.Dynamic.Utils.CacheDict`2/Entry::.ctor(System.Int32,TKey,TValue)
// 0x00000107 System.Exception System.Dynamic.Utils.ContractUtils::get_Unreachable()
extern void ContractUtils_get_Unreachable_m792F83C753CCE84550E4F0442CDC49B978FD0CE6 (void);
// 0x00000108 System.Void System.Dynamic.Utils.ContractUtils::RequiresNotNull(System.Object,System.String)
extern void ContractUtils_RequiresNotNull_mD3D07BD7AA85863B8388667F7CD3D14F6886E41D (void);
// 0x00000109 System.Reflection.ParameterInfo[] System.Dynamic.Utils.TypeExtensions::GetParametersCached(System.Reflection.MethodBase)
extern void TypeExtensions_GetParametersCached_mD2B9864864929FEFA691059A59077A7E491A8141 (void);
// 0x0000010A System.Void System.Dynamic.Utils.TypeExtensions::.cctor()
extern void TypeExtensions__cctor_m0F364DE486F72C0E269E59B71A9E0C3F7E4E089C (void);
// 0x0000010B System.Boolean System.Dynamic.Utils.TypeUtils::IsNullableType(System.Type)
extern void TypeUtils_IsNullableType_m0ECBA329F82B0EFEBF884984D637FD55361F3AD0 (void);
// 0x0000010C System.Boolean System.Dynamic.Utils.TypeUtils::AreEquivalent(System.Type,System.Type)
extern void TypeUtils_AreEquivalent_m0BABD4C82A94A96D19CCA4B9A7788B436049BC65 (void);
// 0x0000010D System.Boolean System.Dynamic.Utils.TypeUtils::AreReferenceAssignable(System.Type,System.Type)
extern void TypeUtils_AreReferenceAssignable_m2153DADCC06A2E1C36820F736A9F93E6183D0177 (void);
// 0x0000010E System.Reflection.MethodInfo System.Dynamic.Utils.TypeUtils::GetInvokeMethod(System.Type)
extern void TypeUtils_GetInvokeMethod_m62AB477BF6415EEB6F7108534BAB598CA9CDCA02 (void);
// 0x0000010F System.Void System.Dynamic.Utils.TypeUtils::.cctor()
extern void TypeUtils__cctor_mB36C11550B01FFEAF9FC7B99967577D97A50C2ED (void);
// 0x00000110 System.Void System.Dynamic.Utils.TypeUtils/<>c::.cctor()
extern void U3CU3Ec__cctor_m2FDD430879029E78453E21DB26F2A00DE0196692 (void);
// 0x00000111 System.Void System.Dynamic.Utils.TypeUtils/<>c::.ctor()
extern void U3CU3Ec__ctor_m1D47C37129713530A6B1FE13BCB381295704FD22 (void);
// 0x00000112 System.Boolean System.Dynamic.Utils.TypeUtils/<>c::<.cctor>b__44_0(System.Type)
extern void U3CU3Ec_U3C_cctorU3Eb__44_0_m2BD6021A86F56FAF62819F3E8E5C646C33189C84 (void);
// 0x00000113 System.Type System.Dynamic.Utils.TypeUtils/<>c::<.cctor>b__44_1(System.Type)
extern void U3CU3Ec_U3C_cctorU3Eb__44_1_mEC47DD3839EE48CD21585CB1ECD92E8D26693755 (void);
// 0x00000114 System.Void System.Collections.Generic.BitHelper::.ctor(System.Int32*,System.Int32)
extern void BitHelper__ctor_m141F24AE9FFCB3EA3D2C7EA79BDAC722026EDEB3 (void);
// 0x00000115 System.Void System.Collections.Generic.BitHelper::.ctor(System.Int32[],System.Int32)
extern void BitHelper__ctor_m795A92E9A03F57547FD78A8E50F730C2778DDD19 (void);
// 0x00000116 System.Void System.Collections.Generic.BitHelper::MarkBit(System.Int32)
extern void BitHelper_MarkBit_m12EFF71C5444F4E4D076F514C0C0723B39E50F86 (void);
// 0x00000117 System.Boolean System.Collections.Generic.BitHelper::IsMarked(System.Int32)
extern void BitHelper_IsMarked_m0A02826959B4EF6381B8F6C7DF0EDBFC55EE8EF2 (void);
// 0x00000118 System.Int32 System.Collections.Generic.BitHelper::ToIntArrayLength(System.Int32)
extern void BitHelper_ToIntArrayLength_m59204C3775D26A8B9532246C2F384C92D02E713C (void);
// 0x00000119 System.Void System.Collections.Generic.HashSet`1::.ctor()
// 0x0000011A System.Void System.Collections.Generic.HashSet`1::.ctor(System.Collections.Generic.IEqualityComparer`1<T>)
// 0x0000011B System.Void System.Collections.Generic.HashSet`1::.ctor(System.Collections.Generic.IEnumerable`1<T>)
// 0x0000011C System.Void System.Collections.Generic.HashSet`1::.ctor(System.Collections.Generic.IEnumerable`1<T>,System.Collections.Generic.IEqualityComparer`1<T>)
// 0x0000011D System.Void System.Collections.Generic.HashSet`1::.ctor(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
// 0x0000011E System.Void System.Collections.Generic.HashSet`1::CopyFrom(System.Collections.Generic.HashSet`1<T>)
// 0x0000011F System.Void System.Collections.Generic.HashSet`1::System.Collections.Generic.ICollection<T>.Add(T)
// 0x00000120 System.Void System.Collections.Generic.HashSet`1::Clear()
// 0x00000121 System.Boolean System.Collections.Generic.HashSet`1::Contains(T)
// 0x00000122 System.Void System.Collections.Generic.HashSet`1::CopyTo(T[],System.Int32)
// 0x00000123 System.Boolean System.Collections.Generic.HashSet`1::Remove(T)
// 0x00000124 System.Int32 System.Collections.Generic.HashSet`1::get_Count()
// 0x00000125 System.Boolean System.Collections.Generic.HashSet`1::System.Collections.Generic.ICollection<T>.get_IsReadOnly()
// 0x00000126 System.Collections.Generic.HashSet`1/Enumerator<T> System.Collections.Generic.HashSet`1::GetEnumerator()
// 0x00000127 System.Collections.Generic.IEnumerator`1<T> System.Collections.Generic.HashSet`1::System.Collections.Generic.IEnumerable<T>.GetEnumerator()
// 0x00000128 System.Collections.IEnumerator System.Collections.Generic.HashSet`1::System.Collections.IEnumerable.GetEnumerator()
// 0x00000129 System.Void System.Collections.Generic.HashSet`1::GetObjectData(System.Runtime.Serialization.SerializationInfo,System.Runtime.Serialization.StreamingContext)
// 0x0000012A System.Void System.Collections.Generic.HashSet`1::OnDeserialization(System.Object)
// 0x0000012B System.Boolean System.Collections.Generic.HashSet`1::Add(T)
// 0x0000012C System.Void System.Collections.Generic.HashSet`1::UnionWith(System.Collections.Generic.IEnumerable`1<T>)
// 0x0000012D System.Void System.Collections.Generic.HashSet`1::IntersectWith(System.Collections.Generic.IEnumerable`1<T>)
// 0x0000012E System.Void System.Collections.Generic.HashSet`1::ExceptWith(System.Collections.Generic.IEnumerable`1<T>)
// 0x0000012F System.Void System.Collections.Generic.HashSet`1::SymmetricExceptWith(System.Collections.Generic.IEnumerable`1<T>)
// 0x00000130 System.Boolean System.Collections.Generic.HashSet`1::IsSubsetOf(System.Collections.Generic.IEnumerable`1<T>)
// 0x00000131 System.Boolean System.Collections.Generic.HashSet`1::IsProperSubsetOf(System.Collections.Generic.IEnumerable`1<T>)
// 0x00000132 System.Boolean System.Collections.Generic.HashSet`1::IsSupersetOf(System.Collections.Generic.IEnumerable`1<T>)
// 0x00000133 System.Boolean System.Collections.Generic.HashSet`1::IsProperSupersetOf(System.Collections.Generic.IEnumerable`1<T>)
// 0x00000134 System.Boolean System.Collections.Generic.HashSet`1::Overlaps(System.Collections.Generic.IEnumerable`1<T>)
// 0x00000135 System.Boolean System.Collections.Generic.HashSet`1::SetEquals(System.Collections.Generic.IEnumerable`1<T>)
// 0x00000136 System.Void System.Collections.Generic.HashSet`1::CopyTo(T[])
// 0x00000137 System.Void System.Collections.Generic.HashSet`1::CopyTo(T[],System.Int32,System.Int32)
// 0x00000138 System.Int32 System.Collections.Generic.HashSet`1::RemoveWhere(System.Predicate`1<T>)
// 0x00000139 System.Collections.Generic.IEqualityComparer`1<T> System.Collections.Generic.HashSet`1::get_Comparer()
// 0x0000013A System.Void System.Collections.Generic.HashSet`1::TrimExcess()
// 0x0000013B System.Int32 System.Collections.Generic.HashSet`1::Initialize(System.Int32)
// 0x0000013C System.Void System.Collections.Generic.HashSet`1::IncreaseCapacity()
// 0x0000013D System.Void System.Collections.Generic.HashSet`1::SetCapacity(System.Int32)
// 0x0000013E System.Boolean System.Collections.Generic.HashSet`1::AddIfNotPresent(T)
// 0x0000013F System.Void System.Collections.Generic.HashSet`1::AddValue(System.Int32,System.Int32,T)
// 0x00000140 System.Boolean System.Collections.Generic.HashSet`1::ContainsAllElements(System.Collections.Generic.IEnumerable`1<T>)
// 0x00000141 System.Boolean System.Collections.Generic.HashSet`1::IsSubsetOfHashSetWithSameEC(System.Collections.Generic.HashSet`1<T>)
// 0x00000142 System.Void System.Collections.Generic.HashSet`1::IntersectWithHashSetWithSameEC(System.Collections.Generic.HashSet`1<T>)
// 0x00000143 System.Void System.Collections.Generic.HashSet`1::IntersectWithEnumerable(System.Collections.Generic.IEnumerable`1<T>)
// 0x00000144 System.Int32 System.Collections.Generic.HashSet`1::InternalIndexOf(T)
// 0x00000145 System.Void System.Collections.Generic.HashSet`1::SymmetricExceptWithUniqueHashSet(System.Collections.Generic.HashSet`1<T>)
// 0x00000146 System.Void System.Collections.Generic.HashSet`1::SymmetricExceptWithEnumerable(System.Collections.Generic.IEnumerable`1<T>)
// 0x00000147 System.Boolean System.Collections.Generic.HashSet`1::AddOrGetLocation(T,System.Int32&)
// 0x00000148 System.Collections.Generic.HashSet`1/ElementCount<T> System.Collections.Generic.HashSet`1::CheckUniqueAndUnfoundElements(System.Collections.Generic.IEnumerable`1<T>,System.Boolean)
// 0x00000149 System.Boolean System.Collections.Generic.HashSet`1::AreEqualityComparersEqual(System.Collections.Generic.HashSet`1<T>,System.Collections.Generic.HashSet`1<T>)
// 0x0000014A System.Int32 System.Collections.Generic.HashSet`1::InternalGetHashCode(T)
// 0x0000014B System.Void System.Collections.Generic.HashSet`1/Enumerator::.ctor(System.Collections.Generic.HashSet`1<T>)
// 0x0000014C System.Void System.Collections.Generic.HashSet`1/Enumerator::Dispose()
// 0x0000014D System.Boolean System.Collections.Generic.HashSet`1/Enumerator::MoveNext()
// 0x0000014E T System.Collections.Generic.HashSet`1/Enumerator::get_Current()
// 0x0000014F System.Object System.Collections.Generic.HashSet`1/Enumerator::System.Collections.IEnumerator.get_Current()
// 0x00000150 System.Void System.Collections.Generic.HashSet`1/Enumerator::System.Collections.IEnumerator.Reset()
// 0x00000151 System.Void System.Collections.Generic.ICollectionDebugView`1::.ctor(System.Collections.Generic.ICollection`1<T>)
// 0x00000152 T[] System.Collections.Generic.ICollectionDebugView`1::get_Items()
static Il2CppMethodPointer s_methodPointers[338] = 
{
	SR_Format_m7198B645F5C0A5E33F30AEF003C1F1D1415A9F86,
	Error_ArgumentNull_m1141D2C9AF8AB6ACC45E7488789598C5283D4EEE,
	Error_MoreThanOneMatch_mE8ABBCC1C5FBA4D7BBE5B0647992D20F005F7A97,
	Error_NoElements_m49C996124733B026EA2FDBE9382AAD136CA22362,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	Enumerable_Min_m3D3C3E5CE25D27D94448CA832FB5AB9F702D5443,
	Enumerable_Max_mF33848068459BE74BF534D16F6B678BB677EE704,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	Expression_get_NodeType_m86A459B820D793551B0728F93F345B1B1241184F,
	Expression_get_Type_m4AC9DBEF56D88946B63069DEB3BE1B7C3B5EAF06,
	Expression_get_CanReduce_m30EE3C351EA9FC2CC69587517388669524078688,
	Expression_Reduce_mC29568DCEEDB09AF835AA0339448DE3502333D01,
	Expression_VisitChildren_m06C46AA86F547C59012080E420831412F0FEA9AC,
	Expression_Accept_mFB922854EC333F269F5994CE65B86A30189E0F65,
	Expression_ReduceAndCheck_m8CF664E3CC592955516A833A9AF4A42278AF46C0,
	Expression_get_DebugView_mE3D40DC10A0290401CADA46440DBCE8521048D92,
	Expression__cctor_mE34384A199AAD190A67CF73E7F9806FC3B8CA754,
	LambdaExpressionProxy__ctor_m853CB81D9E6F6492B6726A8B7CA421A857F3DBF8,
	LambdaExpressionProxy_get_Body_mEEB6B316074140914C3A928392AEED75E3859F6F,
	LambdaExpressionProxy_get_CanReduce_mF2A55247DA047343B063DE7CD9A7EC9F91C9A2A6,
	LambdaExpressionProxy_get_DebugView_m1A2BFAE18A9B72415686F010A6E1B2341E386545,
	LambdaExpressionProxy_get_Name_m5EA9B36355FA2F5353686BA1261D5C12A5B1C5D8,
	LambdaExpressionProxy_get_NodeType_mB58407D2E69616F9FE1DE716BB16B1972FFF1657,
	LambdaExpressionProxy_get_Parameters_m359BEC19A66BB4CF0D3A7FF11A370C0D85B88E31,
	LambdaExpressionProxy_get_ReturnType_m97676A2B02AA0AA2AD179385D87AAF5483DC973D,
	LambdaExpressionProxy_get_TailCall_mC77892AA06C0026967D925D92C476C47748F0CB8,
	LambdaExpressionProxy_get_Type_mCE70232EC775F8BA2843B4E17FA82139B8919CDB,
	MemberExpressionProxy__ctor_mC505DDCAFD0FAFE7B1115269A0EFDA56B28D1F9C,
	MemberExpressionProxy_get_CanReduce_m17A87F8630972D0061E29C04A7EAEB6A0D79FBA3,
	MemberExpressionProxy_get_DebugView_m6CB9DAB1FB28080346B1AF731A6C9F0EAB132BD6,
	MemberExpressionProxy_get_Expression_m621D062B8613F0F302F61BB24F84D0EE6CF9271C,
	MemberExpressionProxy_get_Member_mEF38502CD36FF63495CCE4DD84ED96FAB216911A,
	MemberExpressionProxy_get_NodeType_mEA7E810ED6B75385171F436DD0640B88C101E922,
	MemberExpressionProxy_get_Type_mC3046CD402C885777AC01CDA6F395B74C49BAEAC,
	ParameterExpressionProxy__ctor_m5B0728A97F390E91B95AAA208BF67E6635F3168F,
	ParameterExpressionProxy_get_CanReduce_mD2773677857D9DE3ADBDD4BC75DE1615A49CB841,
	ParameterExpressionProxy_get_DebugView_m02E853F0E274A8BB71AA96D68D98FB9DDDC5DC7D,
	ParameterExpressionProxy_get_IsByRef_mEDDDDE67041C802EC1021B2AB3D1F267F742A57E,
	ParameterExpressionProxy_get_Name_m069CA1BE4083596E2F09703FF6CFCDB7C49ACF9E,
	ParameterExpressionProxy_get_NodeType_mDDBBD7FEF560C6828F2D7EDFDB9D845BFFF6FB33,
	ParameterExpressionProxy_get_Type_m0A29FD9A32EE5EB9DC4C6D14E7DF918AF151C279,
	UnaryExpressionProxy__ctor_m808A75668E3F5C527AD3638EB6634E8F8EB3D495,
	UnaryExpressionProxy_get_CanReduce_m99FD7F141DC656290A3D10FADFAFA7D26A6D4E64,
	UnaryExpressionProxy_get_DebugView_m69448791B12B247D7CA5AFEC1C89B6F597ABC9D1,
	UnaryExpressionProxy_get_IsLifted_m1451664C4E86501939C109FFE8011D7CB9F10099,
	UnaryExpressionProxy_get_IsLiftedToNull_m1A6445847373D85512EAE96F0FD4D94AE2839E11,
	UnaryExpressionProxy_get_Method_m022EBA7324513D794AFF7E2AF51142D951A14EE6,
	UnaryExpressionProxy_get_NodeType_m2996E8478351A94B92C9FA4CFB9DF756436D13B5,
	UnaryExpressionProxy_get_Operand_m1012230FA895135E9B50FBF54FD800CF17D49FB7,
	UnaryExpressionProxy_get_Type_m536DC0A928B0F4C3D3EDAC5E203E25FBEEAB8AB1,
	DebugViewWriter__ctor_m7F103C336119E054D04D04D2974EC2FC94BC4C2D,
	DebugViewWriter_get_Base_m4B18E918536DC2C2C9777364A3D02A655D7D7625,
	DebugViewWriter_get_Delta_m1D601E610796CF9861B231605DC41D5864BEBF4F,
	DebugViewWriter_get_Depth_m6EFA4F708BC2B32263E24AEED59B7E9F489574E2,
	DebugViewWriter_Indent_mEAAF7F8119D723B4363486B39EC5EFF8357CA3C3,
	DebugViewWriter_Dedent_m32EEF64C20FEF360759C16BB3440A0F9E9E5A62C,
	DebugViewWriter_NewLine_mC3DFE844CA2802D707700A17D0488AF5051C2E98,
	NULL,
	DebugViewWriter_GetLambdaId_mECC1286C8EECCB4D771239797B5E678DA5F506B1,
	DebugViewWriter_GetParamId_m7EDDA26EC415F7327CDAA447D6701B29184C0429,
	DebugViewWriter_WriteTo_m74A8ACEE24D5C6425D528F0F1D4E70C57193BD3D,
	DebugViewWriter_WriteTo_m2F19CE592AD660AAF040AE83EE73E0DFE8BA47F9,
	DebugViewWriter_Out_m015226FD79DC9842D02C8E6C2C9DD03E134D9A18,
	DebugViewWriter_Out_m059DB7930ACD59E21849BA341D4D251F4BE6FD8F,
	DebugViewWriter_Out_mDF85CA38ABF60A7EE3853A409B6391E0AF26168C,
	DebugViewWriter_Out_m5C225831A3A1ABF3C48F2CED090D66B25B9411D8,
	DebugViewWriter_WriteLine_mAD23CC084D2310A35BB26FF1921CA61A9C0224F8,
	DebugViewWriter_Write_m3E7ACA1062A8C9466A1E9939A3CA6074787EC6B3,
	DebugViewWriter_GetFlow_m5307C3DBBAD119486501B7C6A3A8B5C69BEE878B,
	DebugViewWriter_CheckBreak_mB788A594EE2531CC5BBC3676CB9AB54D5D440E5C,
	DebugViewWriter_VisitDeclarations_m667EF88D9F3B2A3D04E04933E3B5E77E80A7144A,
	NULL,
	DebugViewWriter_VisitParameter_m6B5BDB5A5411936A8E29F70D402635686E3B5E27,
	DebugViewWriter_VisitExtension_mEBBED9DCECCED1EA1DC2DC5EE1B25341E005C3AA,
	DebugViewWriter_WriteLambda_mA319115AC57D05C6B2A875F88F71DD6AC98A27B2,
	DebugViewWriter_GetLambdaName_m080552587E1A86C78B612178334641B12CDA57D4,
	DebugViewWriter_ContainsWhiteSpace_mF9D69062D6A1E7E604F78AD0F9146CCC763C26DF,
	DebugViewWriter_QuoteName_mCE3A53E4D1F177BA67846D19C4EDF063B534F493,
	DebugViewWriter_GetDisplayName_m680F00E5FF2145619CB898F80E22135AE59619EA,
	DebugViewWriter_U3CVisitDeclarationsU3Eb__38_0_m638E405BD92F9E070928D5E8253C862CB0368A0F,
	Error_ReducibleMustOverrideReduce_m369D2EDF8DD292F0CEBAE0991AF5C9F1CA276DD6,
	Error_MustReduceToDifferent_m36A8F6F0A3AE082814045AF5125981212C36D38B,
	Error_ReducedNotCompatible_m597288FC7F20F76ED7EE7A79157914643C661FFE,
	Error_MustBeReducible_mED85C31673392919ACFE804F81190778783975A7,
	Error_ExtensionNodeMustOverrideProperty_mD5BBC9AEE0B7601E3814C967A521A87A5713EB39,
	ExpressionVisitor__ctor_m2974B344C35DD823BDA6D6313DAE4C7F64541393,
	ExpressionVisitor_Visit_mCC12DFA654B568E00CA4FD5A38C284FDF542FA6D,
	ExpressionVisitor_VisitExtension_m16258F15F7B3BE8BAE1BB3090AC741E471F46F2D,
	ExpressionVisitor_VisitParameter_m66B44224F5F0ACF016A5C1652CD09B9AEA9AFC14,
	LambdaExpression_get_Parameters_m60512B6B3670A57CD4789335522EB4CAEF59A05F,
	LambdaExpression_get_Name_mC099AAE16A8765B43A0D835C6AB33DFA80D4F878,
	LambdaExpression_get_NameCore_m9CE950CD0859EA1BAA728850D353EF2292D5037C,
	LambdaExpression_get_Body_m161E156442547AE8A6837C5AE065BD93345451DE,
	LambdaExpression_get_ReturnType_mA8E8D3FF1557408AFB1CE8C1B7ED879F045D41FB,
	LambdaExpression_get_TailCall_m5C8FF396DC74BF7D57D40A22040CF500FABAE2E5,
	LambdaExpression_get_TailCallCore_m76CF7B1A957240BC996993CD94E34FB49634CCCC,
	LambdaExpression_GetOrMakeParameters_m2627C12ACFCE4104415D9B9661BC5D4EF4521A7A,
	MemberExpression_get_Member_m30A7DCC7673A38BE9F06597DC9F5305E61B88104,
	MemberExpression_get_Expression_mF422466944A9875383573A4FD01CD661C64B7503,
	MemberExpression_GetMember_mB44F09D4104C91F27C0F3246C222224728A9C3FC,
	ParameterExpression_get_Name_m5F48CE2BAC279432E92DC3AFBF627F234D0E1D2A,
	ParameterExpression_get_IsByRef_m01BDD008CE1E89DE90DA5D35E951949CC665FE1C,
	ParameterExpression_GetIsByRef_m8F08D04AA3BDD969B05F5B95101D5576DD59E4D6,
	Strings_get_ReducibleMustOverrideReduce_m3A42A36C78DEE542AE7861CCE517D5B05AD822B1,
	Strings_get_MustReduceToDifferent_m958D994C04C8CB086B7C38E609E24FFC47E5265B,
	Strings_get_ReducedNotCompatible_mDE70EE4B9AD1B81B7341E17740056421BF7ECD7D,
	Strings_get_MustBeReducible_m6AA622B4FC648A5A1B05D4CC21B9EB4A77600B79,
	Strings_ExtensionNodeMustOverrideProperty_m9104CAA7D2A9E08CBB135788A14930D2B9720284,
	UnaryExpression_get_Operand_mE144387E98BABF0D3FD8E4640612A726D91E2943,
	UnaryExpression_get_Method_mA8D37E71BEA657B6999A51277A7D7CBDF951E265,
	UnaryExpression_get_IsLifted_m06A58D1977585CE5EFC1FEB58128DF06A5F8C626,
	UnaryExpression_get_IsLiftedToNull_m6A6103EBBB80AB1A349197D7E562B2B4898AC38E,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	ContractUtils_get_Unreachable_m792F83C753CCE84550E4F0442CDC49B978FD0CE6,
	ContractUtils_RequiresNotNull_mD3D07BD7AA85863B8388667F7CD3D14F6886E41D,
	TypeExtensions_GetParametersCached_mD2B9864864929FEFA691059A59077A7E491A8141,
	TypeExtensions__cctor_m0F364DE486F72C0E269E59B71A9E0C3F7E4E089C,
	TypeUtils_IsNullableType_m0ECBA329F82B0EFEBF884984D637FD55361F3AD0,
	TypeUtils_AreEquivalent_m0BABD4C82A94A96D19CCA4B9A7788B436049BC65,
	TypeUtils_AreReferenceAssignable_m2153DADCC06A2E1C36820F736A9F93E6183D0177,
	TypeUtils_GetInvokeMethod_m62AB477BF6415EEB6F7108534BAB598CA9CDCA02,
	TypeUtils__cctor_mB36C11550B01FFEAF9FC7B99967577D97A50C2ED,
	U3CU3Ec__cctor_m2FDD430879029E78453E21DB26F2A00DE0196692,
	U3CU3Ec__ctor_m1D47C37129713530A6B1FE13BCB381295704FD22,
	U3CU3Ec_U3C_cctorU3Eb__44_0_m2BD6021A86F56FAF62819F3E8E5C646C33189C84,
	U3CU3Ec_U3C_cctorU3Eb__44_1_mEC47DD3839EE48CD21585CB1ECD92E8D26693755,
	BitHelper__ctor_m141F24AE9FFCB3EA3D2C7EA79BDAC722026EDEB3,
	BitHelper__ctor_m795A92E9A03F57547FD78A8E50F730C2778DDD19,
	BitHelper_MarkBit_m12EFF71C5444F4E4D076F514C0C0723B39E50F86,
	BitHelper_IsMarked_m0A02826959B4EF6381B8F6C7DF0EDBFC55EE8EF2,
	BitHelper_ToIntArrayLength_m59204C3775D26A8B9532246C2F384C92D02E713C,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
};
static const int32_t s_InvokerIndices[338] = 
{
	8423,
	9135,
	9540,
	9540,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	9025,
	9025,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	6045,
	6078,
	5977,
	6078,
	4294,
	4294,
	6078,
	6078,
	9583,
	4886,
	6078,
	5977,
	6078,
	6078,
	6045,
	6078,
	6078,
	5977,
	6078,
	4886,
	5977,
	6078,
	6078,
	6078,
	6045,
	6078,
	4886,
	5977,
	6078,
	5977,
	6078,
	6045,
	6078,
	4886,
	5977,
	6078,
	5977,
	5977,
	6078,
	6045,
	6078,
	6078,
	4886,
	6045,
	6045,
	6045,
	6202,
	6202,
	6202,
	0,
	4028,
	4028,
	8698,
	4886,
	4886,
	2428,
	2652,
	1296,
	6202,
	4886,
	4005,
	4005,
	4886,
	0,
	4294,
	4294,
	4886,
	4294,
	8919,
	9135,
	9135,
	4886,
	9540,
	9540,
	9540,
	9540,
	9135,
	6202,
	4294,
	4294,
	4294,
	6078,
	6078,
	6078,
	6078,
	6078,
	5977,
	5977,
	6078,
	6078,
	6078,
	6078,
	6078,
	5977,
	5977,
	9540,
	9540,
	9540,
	9540,
	9135,
	6078,
	6078,
	5977,
	5977,
	0,
	0,
	0,
	0,
	0,
	0,
	9540,
	8698,
	9135,
	9583,
	8919,
	8178,
	8178,
	9135,
	9583,
	9583,
	6202,
	3426,
	4294,
	2141,
	2652,
	4857,
	3398,
	9020,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
};
static const Il2CppTokenRangePair s_rgctxIndices[66] = 
{
	{ 0x02000005, { 142, 5 } },
	{ 0x02000006, { 147, 13 } },
	{ 0x02000007, { 162, 9 } },
	{ 0x02000008, { 173, 14 } },
	{ 0x02000009, { 189, 16 } },
	{ 0x0200000A, { 208, 12 } },
	{ 0x0200000B, { 223, 17 } },
	{ 0x0200000C, { 243, 2 } },
	{ 0x0200000D, { 245, 4 } },
	{ 0x0200000E, { 249, 17 } },
	{ 0x0200000F, { 266, 10 } },
	{ 0x02000010, { 276, 13 } },
	{ 0x02000011, { 289, 13 } },
	{ 0x02000012, { 302, 2 } },
	{ 0x02000014, { 304, 10 } },
	{ 0x02000016, { 314, 3 } },
	{ 0x02000017, { 319, 7 } },
	{ 0x02000018, { 326, 8 } },
	{ 0x02000019, { 334, 4 } },
	{ 0x0200001A, { 338, 10 } },
	{ 0x0200001B, { 348, 8 } },
	{ 0x0200002D, { 369, 9 } },
	{ 0x02000034, { 378, 58 } },
	{ 0x02000037, { 436, 3 } },
	{ 0x02000038, { 439, 4 } },
	{ 0x06000005, { 0, 10 } },
	{ 0x06000006, { 10, 10 } },
	{ 0x06000007, { 20, 5 } },
	{ 0x06000008, { 25, 5 } },
	{ 0x06000009, { 30, 1 } },
	{ 0x0600000A, { 31, 2 } },
	{ 0x0600000B, { 33, 1 } },
	{ 0x0600000C, { 34, 2 } },
	{ 0x0600000D, { 36, 2 } },
	{ 0x0600000E, { 38, 2 } },
	{ 0x0600000F, { 40, 1 } },
	{ 0x06000010, { 41, 2 } },
	{ 0x06000011, { 43, 1 } },
	{ 0x06000012, { 44, 2 } },
	{ 0x06000013, { 46, 4 } },
	{ 0x06000014, { 50, 2 } },
	{ 0x06000015, { 52, 1 } },
	{ 0x06000016, { 53, 11 } },
	{ 0x06000017, { 64, 8 } },
	{ 0x06000018, { 72, 8 } },
	{ 0x06000019, { 80, 6 } },
	{ 0x0600001A, { 86, 8 } },
	{ 0x0600001B, { 94, 6 } },
	{ 0x0600001C, { 100, 6 } },
	{ 0x0600001D, { 106, 1 } },
	{ 0x0600001E, { 107, 2 } },
	{ 0x0600001F, { 109, 6 } },
	{ 0x06000020, { 115, 6 } },
	{ 0x06000021, { 121, 4 } },
	{ 0x06000022, { 125, 6 } },
	{ 0x06000023, { 131, 3 } },
	{ 0x06000024, { 134, 8 } },
	{ 0x06000036, { 160, 2 } },
	{ 0x0600003B, { 171, 2 } },
	{ 0x06000040, { 187, 2 } },
	{ 0x06000046, { 205, 3 } },
	{ 0x0600004B, { 220, 3 } },
	{ 0x06000050, { 240, 3 } },
	{ 0x06000085, { 317, 2 } },
	{ 0x060000CA, { 356, 5 } },
	{ 0x060000D8, { 361, 8 } },
};
extern const uint32_t g_rgctx_Iterator_1_tAFB7558C92D3848C170203685AA45B10B6035464;
extern const uint32_t g_rgctx_Iterator_1_Where_mB33345A6D2213AB59B7B357292542E752C9AEEF2;
extern const uint32_t g_rgctx_TSourceU5BU5D_t5F9558857B1D501A57AAC7DDF5A60A1CAF6A8736;
extern const uint32_t g_rgctx_WhereArrayIterator_1_t8F188FD6974943DFDC1A3C36E69549C9146DCB25;
extern const uint32_t g_rgctx_WhereArrayIterator_1__ctor_mFE764A6F32B18EEABDD6813CF733205E2149C7B7;
extern const uint32_t g_rgctx_List_1_t8601446322D050B44EBF5C49E8048407F11D6239;
extern const uint32_t g_rgctx_WhereListIterator_1_tDAFC464D33DAF1B893DB760F55638A7AC019AEB9;
extern const uint32_t g_rgctx_WhereListIterator_1__ctor_m0D87B2EFC00BD5C900E47BED483C334DC731E51D;
extern const uint32_t g_rgctx_WhereEnumerableIterator_1_tB9885E49C2A0467CBEB9B331919AE76488DD4BA8;
extern const uint32_t g_rgctx_WhereEnumerableIterator_1__ctor_m7CA177F283ABFD6426F57A5630315F53267741CE;
extern const uint32_t g_rgctx_Iterator_1_t83549F4A854FAE4651C92A7B3B8907E4798F0121;
extern const uint32_t g_rgctx_Iterator_1_Select_TisTResult_tF3AC1D6143237427ECB7A483D967C1FE5374DBD7_mC9EEBF5649EB6F682C5621B1AF6786BFFC2C62B4;
extern const uint32_t g_rgctx_TSourceU5BU5D_tD0F38A3B04FEF1F6EB6A2C0F97C2F6826A3C1198;
extern const uint32_t g_rgctx_WhereSelectArrayIterator_2_tD31A5253F7EAAB16463FB95C4B1DF1B5BA0BE6DE;
extern const uint32_t g_rgctx_WhereSelectArrayIterator_2__ctor_m85B91DA1F46361240445ADE95E0CFD6F1674C1FA;
extern const uint32_t g_rgctx_List_1_t7FCC2F8DB1446378C6AD15E4C2ECDCB8E2001280;
extern const uint32_t g_rgctx_WhereSelectListIterator_2_tE91BB456A01CEF4F6BC613FDF4A44F341B2D7206;
extern const uint32_t g_rgctx_WhereSelectListIterator_2__ctor_m0D002693B7EAB5A831D2058278463032864687DC;
extern const uint32_t g_rgctx_WhereSelectEnumerableIterator_2_t9583448D4FAA842B0C18940E2557F5D5A9507364;
extern const uint32_t g_rgctx_WhereSelectEnumerableIterator_2__ctor_m8F12E12FDDE5F7E663BA04C6B41490D162423694;
extern const uint32_t g_rgctx_U3CU3Ec__DisplayClass6_0_1_t0D7DCEEA7C4415169B2CBD5801DECF1AE6BC71D1;
extern const uint32_t g_rgctx_U3CU3Ec__DisplayClass6_0_1__ctor_mC075FAA755826D869270E4A74AED806B91B2E5F3;
extern const uint32_t g_rgctx_U3CU3Ec__DisplayClass6_0_1_U3CCombinePredicatesU3Eb__0_m6F0EDB0FF04C8A3C9C6D97800722D1B3851C415C;
extern const uint32_t g_rgctx_Func_2_t39F15D2C4961B652B7F6B0AD725F37F96D8C9F54;
extern const uint32_t g_rgctx_Func_2__ctor_m18DE7FE4BDFFE701174935655A7EFBA6D405ACA1;
extern const uint32_t g_rgctx_U3CU3Ec__DisplayClass7_0_3_tCCDD433A1A5065F08529A9FCE5D0C53B52F7B3A6;
extern const uint32_t g_rgctx_U3CU3Ec__DisplayClass7_0_3__ctor_m248BC6F9C9006A172D95E4482735B14F94409558;
extern const uint32_t g_rgctx_U3CU3Ec__DisplayClass7_0_3_U3CCombineSelectorsU3Eb__0_mEFA4E2467394FB8379F3CCA7A61136C96768B2BD;
extern const uint32_t g_rgctx_Func_2_t09635D19844B1DE3B9DF944B0517FBF783EA917C;
extern const uint32_t g_rgctx_Func_2__ctor_mB0725395805DF6905CB0FAA6BB81FFAAB17AEA93;
extern const uint32_t g_rgctx_Enumerable_SelectManyIterator_TisTSource_t4F1C6525D7158568B966831E7E458E67ED1E17D1_TisTResult_t9FFE0CF4D9F15D47CE62F5B4E43A1576839D17F7_mCEA61666E9C42D2C3C1990FE4AE94726B960FC29;
extern const uint32_t g_rgctx_U3CSelectManyIteratorU3Ed__17_2_t3E6366BB538F1DDBAE53C058F82E7732A67C1066;
extern const uint32_t g_rgctx_U3CSelectManyIteratorU3Ed__17_2__ctor_m41401D6425C84176DD5D979BD2B4ACBD3C62A542;
extern const uint32_t g_rgctx_Enumerable_TakeIterator_TisTSource_t9A3EEA082DFE478BD5E5693EF0D5A2543F9F41A3_mBC464106C0C176599F4DE02CB48B29E8516FDACB;
extern const uint32_t g_rgctx_U3CTakeIteratorU3Ed__25_1_tED8E1AA891BB8AFFD61E1A2A2929C7912E8C663C;
extern const uint32_t g_rgctx_U3CTakeIteratorU3Ed__25_1__ctor_mB3FBA9A03B2188F6A1C0BC47507EB4D52B48395B;
extern const uint32_t g_rgctx_OrderedEnumerable_2_t593988007A2B423D75C1D30199B61D4C7E6A838D;
extern const uint32_t g_rgctx_OrderedEnumerable_2__ctor_m31764352760D7E1ADB9FCFFEC381B7F59B0EA831;
extern const uint32_t g_rgctx_IOrderedEnumerable_1_tE159F36B861ADE6AFF40DE4B62A460AAD3A98102;
extern const uint32_t g_rgctx_IOrderedEnumerable_1_CreateOrderedEnumerable_TisTKey_tE566BC5F30D586A72EF9066D4835B59020C31C7D_m7464B73CF6332FE45471C72ECF4BB249382F0D01;
extern const uint32_t g_rgctx_Enumerable_DistinctIterator_TisTSource_tE445F62DD15B96508EDA86F1C195536B774FFCDB_mFC41AF9DA3F7002B250E5752FE1C3033143A6D53;
extern const uint32_t g_rgctx_U3CDistinctIteratorU3Ed__68_1_tCD5DF5274B93EE83954ACF81FB8F2A5A79995FC6;
extern const uint32_t g_rgctx_U3CDistinctIteratorU3Ed__68_1__ctor_mD7880E661DDCD3F4927263534778E64836BF91B5;
extern const uint32_t g_rgctx_Enumerable_ExceptIterator_TisTSource_tE9A48CA2F9C4A502E7DEE0AE573A761AD7F91610_m3711A9E44BFD307B537F0CDE516D45E257735AFE;
extern const uint32_t g_rgctx_U3CExceptIteratorU3Ed__77_1_t36E5C349AEBF5ED105A39E7C4C601C4D1D3DE265;
extern const uint32_t g_rgctx_U3CExceptIteratorU3Ed__77_1__ctor_m3C3A0993FD6D96CD86F2F451EAB73EEE1279BAFE;
extern const uint32_t g_rgctx_Buffer_1_tC3AA32816753DA7B0898D92E15B122AC7DE23B5B;
extern const uint32_t g_rgctx_Buffer_1__ctor_m72F00609851E22DF4338204A2E6EC7E3A3E0C3D4;
extern const uint32_t g_rgctx_Buffer_1_ToArray_m11DBDA9AA16C64F60D134E59D6BD79D515B8D187;
extern const uint32_t g_rgctx_Buffer_1_tC3AA32816753DA7B0898D92E15B122AC7DE23B5B;
extern const uint32_t g_rgctx_List_1_t168E1771B2C2914F0DF873822B754BD4110D6958;
extern const uint32_t g_rgctx_List_1__ctor_mB51694A9EF5013F0A729FC4B8BD80C8A49970CF9;
extern const uint32_t g_rgctx_Enumerable_ToDictionary_TisTSource_tE31865679B90EA41B3B599272398AC4F59C84AFB_TisTKey_tD37952AE661C99DC819D1D703910E923C1FFB563_TisTElement_tC983FBB6789A209AE3741CF7BF97B4518033512E_m581C4145E7A359AB48C48EF4B9FD323449456C1D;
extern const uint32_t g_rgctx_Dictionary_2_t1E70F86BEBC0F1C830579FA6851930E77390E72B;
extern const uint32_t g_rgctx_Dictionary_2__ctor_m591886154E017552D886FC19F4060A03FE424C93;
extern const uint32_t g_rgctx_IEnumerable_1_t5A5C0F89267F3218FAA546F66CD24FEBC7CF84FE;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_mC69AE1ABEA30DF65F14B814D77CAD7C4024E22AB;
extern const uint32_t g_rgctx_IEnumerator_1_tA355CC98E7C1D7ECE78348B13D33CEB831BD17DA;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m50E35714CF970F9143E42B9AEC7B1D77888FC1CA;
extern const uint32_t g_rgctx_Func_2_t5C04A674024FA30035DFC9782FFCAAA61F83788A;
extern const uint32_t g_rgctx_Func_2_Invoke_m0D96BC3A9C1650762AC39C6C5FD483FA60F189DC;
extern const uint32_t g_rgctx_Func_2_t9712D21F02586859B9C521A9A7AF2CF8C070DC73;
extern const uint32_t g_rgctx_Func_2_Invoke_m11C7E19C8CA2288F9AE5440999F048A468CD4306;
extern const uint32_t g_rgctx_Dictionary_2_Add_m008084EDBF8D30C4C632AB28252CC7E324244C92;
extern const uint32_t g_rgctx_IList_1_tCAFCEB62CA7831D3FFCB2DFACB78E4C973717F78;
extern const uint32_t g_rgctx_ICollection_1_t8CAB264343D22D2CB6FA36EE9AA77A7CF44564DF;
extern const uint32_t g_rgctx_ICollection_1_get_Count_m6FA9927538603E9871B9CA77850D733C7610CB02;
extern const uint32_t g_rgctx_IList_1_get_Item_m2A90B8AB52829539BE0F4B737E002A062E1CDF65;
extern const uint32_t g_rgctx_IEnumerable_1_t4E8307BBC992748AA0EE487FDBC0CA86B913A8BA;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_m475176D6069044687168BCA62AB037C5AA651FD9;
extern const uint32_t g_rgctx_IEnumerator_1_t2193CA070A1787F1B1F6BB1E9AB6B209B0028101;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m5DEE1F7FC115E516EC4DC694684D55E2DB387B46;
extern const uint32_t g_rgctx_IList_1_t999E2CCC8893878243576C8C48CDECDDB4CC6138;
extern const uint32_t g_rgctx_ICollection_1_tA93A91F56AB2951AE596AAD0B647F52B66EAA8D9;
extern const uint32_t g_rgctx_ICollection_1_get_Count_mBD9168EF24E0D1CBFEA0D3FBDFD98C141F75A6A8;
extern const uint32_t g_rgctx_IList_1_get_Item_m01B50E739C1FE86F3F18E308F410D60D2CDC5D82;
extern const uint32_t g_rgctx_IEnumerable_1_tBACD95C059639CCD92AB1D12E42424080983FB91;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_m1D2DD2E1A7E1C9612293E4B00474A43F3C0849CE;
extern const uint32_t g_rgctx_IEnumerator_1_tD8DA4BA1989C3A62431320EF709BD2D29BF92FBA;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m167E54B897E90DB0C0B065CD43ED50097BC557F3;
extern const uint32_t g_rgctx_IEnumerable_1_t4D337022429A25D97A21E2A808E1A7D77670440C;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_m65E2270593D5A2B3086CC4C0795F169F9E185559;
extern const uint32_t g_rgctx_IEnumerator_1_tCE654AF887B17BAFC80DB8B6DEB165AA340CFE6D;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m14027FFF40999714DAB3619727F42BE99CAB1D64;
extern const uint32_t g_rgctx_Func_2_tCD33EA8807153BCC10E860849FE539DFF68675FC;
extern const uint32_t g_rgctx_Func_2_Invoke_m9DD7818B0A1D25B61A09AAB142CF267CA4002398;
extern const uint32_t g_rgctx_IList_1_t67F9D0FF82C6B4EC3D4C75A75CBAD190206293C6;
extern const uint32_t g_rgctx_ICollection_1_t97C39C344F2B9DC3B3CAB16756748EF4EF38B6B7;
extern const uint32_t g_rgctx_ICollection_1_get_Count_mF003663592BC97333A81BBAFD7665C7909DDBA5B;
extern const uint32_t g_rgctx_IList_1_get_Item_m66EDBA2B935E97A54009346427D577A753D6A897;
extern const uint32_t g_rgctx_IEnumerable_1_tA747C8672DA999E3B1FDA618DDEF1C4F8FFB07F0;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_mBD3501BF9140CF73945F0497493A6C3FD504A59B;
extern const uint32_t g_rgctx_IEnumerator_1_t915DA07A8E8090EBFC5C149A9629615E0EDDA4C0;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m6AE3FC6684B1E871587122CAFA8744A391B247B5;
extern const uint32_t g_rgctx_IEnumerable_1_t5E257052917A950B3FACC55B8A8A0B49BB974746;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_m1A9475D222D4200965397863EEE4613C6C8A1798;
extern const uint32_t g_rgctx_IEnumerator_1_t3C7A1094806CE6C8A35132A0CA8BB7989E4C9C18;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_mC0C19BE9C96665D7CE321DEDD26AC6C8643901FE;
extern const uint32_t g_rgctx_Func_2_t2CD856C22E0C26253677E18D50FA5D5B15BE1D1B;
extern const uint32_t g_rgctx_Func_2_Invoke_mAA403E7A5C3ABBAB73229A5C25A5E290753BF2A7;
extern const uint32_t g_rgctx_IEnumerable_1_tEF986F81DB6A3163CFD7CDAA423612D3C77639CC;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_m6FB8D118A5176C69DA8D12EE01C540A380D0CA88;
extern const uint32_t g_rgctx_IEnumerator_1_t6F6571CF0B132A4B653D0A40A4193F23DEEC3FD9;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m69FFBE7376E424D93345AD43D1E5D533855DA21A;
extern const uint32_t g_rgctx_Func_2_t3B2B88FD78F5F69347CF2269307A59AC322C79C3;
extern const uint32_t g_rgctx_Func_2_Invoke_mEB89293A67FE90E3AB9DAD0E7E982413D7D44A4D;
extern const uint32_t g_rgctx_EmptyEnumerable_1_tF86C133CF22A6B15D25779DC32AC2D2A0163EAEF;
extern const uint32_t g_rgctx_IEnumerable_1_t87213EF6958E9847E318D7FED68D206925280A0F;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_m623808007A8A20ED9393D48B2467A792BFE9D1D1;
extern const uint32_t g_rgctx_IEnumerable_1_t34C887C840E86896B486F20B42C0F5EAC90C726E;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_m096D45787935CB3519AA751639FA7C8B7B8058FE;
extern const uint32_t g_rgctx_IEnumerator_1_tAC8F51D25D6A25E51E41570AD085263B028F5865;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m0CD4A796E3CAD9965C1EDBF2DD175609DBD87C7D;
extern const uint32_t g_rgctx_Func_2_tECEEE16E2A7D99CED40251A6F6CA091497F39DF9;
extern const uint32_t g_rgctx_Func_2_Invoke_mCF04C711A970D455B890BDBF34E5ABF28518AE9F;
extern const uint32_t g_rgctx_IEnumerable_1_t061DE72820C63A06352F98967548DFD6542B40A9;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_m5548A3DF0D5E42E89B2EFCBC06147F8ED3D90E1E;
extern const uint32_t g_rgctx_IEnumerator_1_t947080FE12F3FB081A1179D1F2EABD2C20A229DB;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m99EBD802C203AAAEF4E8CBEDA3045A4B14FE4013;
extern const uint32_t g_rgctx_Func_2_tF3B6C43F69F4FC1146BDB0626C0AF6D2AE612C0B;
extern const uint32_t g_rgctx_Func_2_Invoke_mEBDE43F80162FF3559BC5F1B5F852D549F9B578E;
extern const uint32_t g_rgctx_ICollection_1_tBDB3D77290C57BA1661C6001A8B5AB96F0ABE3F8;
extern const uint32_t g_rgctx_ICollection_1_get_Count_m100876A0EFAB4C6F2B30D51C36EB3642A847493F;
extern const uint32_t g_rgctx_IEnumerable_1_tF77FB81ADA144B654F79BE6C4272CFD3EB0B6299;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_mAF308FC7FBDEB386D13651EFCD80EEB9EE6F3702;
extern const uint32_t g_rgctx_IEnumerable_1_t8132B77C0BC074307387E78B62BCABC834C87DFB;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_mBDE4817BC08E7BEAAA250EE539FA070F40F2ED43;
extern const uint32_t g_rgctx_IEnumerator_1_t1BAD868D0DFCFD9BD8C92B590DF72B359A37A15E;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m5A18F62B613EFAE2EE43B2791188C445BD664046;
extern const uint32_t g_rgctx_Func_2_t16362D2DFDED0A43A2A5A4EEE13E29A9369B377B;
extern const uint32_t g_rgctx_Func_2_Invoke_m25384294EAEEDBF1541E274BF14CD0BCFA8F3746;
extern const uint32_t g_rgctx_ICollection_1_t143CB03B088368ACAAEEF662B347A36493BD7F74;
extern const uint32_t g_rgctx_ICollection_1_Contains_mB272442975A686EF456CFFBE01CEB6E8F6D0FC4E;
extern const uint32_t g_rgctx_Enumerable_Contains_TisTSource_tF5CADD5C21CF2CD60FD685A28FE7C05B80FA6E8D_mE8A1F4CE22DFFE7ED87F9FA0F0A68FBCDBC3D108;
extern const uint32_t g_rgctx_EqualityComparer_1_get_Default_m70B2467D3FCF463AF4C26D29F891029BF9EC324F;
extern const uint32_t g_rgctx_EqualityComparer_1_t426D9AC8678417217D095C403FD324D997AB36D4;
extern const uint32_t g_rgctx_IEnumerable_1_tE136AE95298B0A325F0358D30EBD0A23EA38B301;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_mDA3FB122CDC182176702AA6A1F57FABCD6AD1894;
extern const uint32_t g_rgctx_IEnumerator_1_t9DF8767078BE055C6FAF64E02370FECE881D6C38;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m552C8A44C35954659B21BF216ADCB1BDADDF7FB0;
extern const uint32_t g_rgctx_IEqualityComparer_1_t44B0DD0F5552A29B47C50C45ED1102424C434AFA;
extern const uint32_t g_rgctx_IEqualityComparer_1_Equals_mBA41CDA0188EDB9E4464E08B7C9FCE7BD9B6F3A4;
extern const uint32_t g_rgctx_Iterator_1_t8E009DFA0514DB4E4987BB392D13A5A8170ECCE4;
extern const uint32_t g_rgctx_Iterator_1_Clone_m06A7D1B0BDA308E69987DDED84FFC6B95859AA62;
extern const uint32_t g_rgctx_Iterator_1_get_Current_m7CDFA0D6C9FE9C1400547F6BDB614EFD06F9BD91;
extern const uint32_t g_rgctx_TSource_tE11DAFD922BE8DFEB5489CBD1813EB0466BC3D79;
extern const uint32_t g_rgctx_Iterator_1_GetEnumerator_mF75249EC97644B0005490D15C69E49F7F9164A90;
extern const uint32_t g_rgctx_Iterator_1__ctor_m690C659CF11A74EED9E70752C5849F1628230AC8;
extern const uint32_t g_rgctx_Iterator_1_t15119AB906B4942B10DE36D501F127F0FF6DF281;
extern const uint32_t g_rgctx_WhereEnumerableIterator_1_t92EE9D2E5265D8B183ED697686240F506BCA8424;
extern const uint32_t g_rgctx_WhereEnumerableIterator_1__ctor_m9C038F85EC321BD8F7AE403D683D0153D355F9CB;
extern const uint32_t g_rgctx_Iterator_1_Dispose_mF10F128ADF4C88061B584756801E3C39F4D04FA6;
extern const uint32_t g_rgctx_IEnumerable_1_t6BB9BE6EEAECF4E66C19B7781D16F0E830520AC0;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_m844DCC57B48252D74DFA627000935F7B4A4407F6;
extern const uint32_t g_rgctx_IEnumerator_1_t7057BF629F81E7DFB90FC10A9074D9A504C6971C;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m07F9232B3524F24682301D1CF8573D7A1CB9C6ED;
extern const uint32_t g_rgctx_Func_2_tC86143735420E666A856DEA89A154669337AD033;
extern const uint32_t g_rgctx_Func_2_Invoke_m12DE18B02FB8945CB56D98F22BD68442081B02EC;
extern const uint32_t g_rgctx_Iterator_1_t15119AB906B4942B10DE36D501F127F0FF6DF281;
extern const uint32_t g_rgctx_Enumerable_CombinePredicates_TisTSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB_m8E8EBCD3C0944D40734F2D3BACA2FF6D133C10EC;
extern const uint32_t g_rgctx_WhereSelectEnumerableIterator_2_t1F5FF34DBCE1F6AF7517393D73D356A6DA50B6D1;
extern const uint32_t g_rgctx_WhereSelectEnumerableIterator_2__ctor_mF3A2E2792E40371499F8A04F1C4B4CF725C70204;
extern const uint32_t g_rgctx_Iterator_1__ctor_mB182060F0BAD71C29739D1A67593C75D932D1F99;
extern const uint32_t g_rgctx_Iterator_1_t401B0AE4A7AE625421285FB386F87D7EB1213E82;
extern const uint32_t g_rgctx_WhereArrayIterator_1_t3191C8D5170E56806A48BD846333ABBD99D3D3C7;
extern const uint32_t g_rgctx_WhereArrayIterator_1__ctor_m4D241BD7A7C7BF59DEFF9D7D34B8E23771934CFE;
extern const uint32_t g_rgctx_Func_2_t9550E469110084BCEB11807FD34F94E9615475E5;
extern const uint32_t g_rgctx_Func_2_Invoke_mCC45E416C5C54731DCA65FEFD545FDC5F4D10DA7;
extern const uint32_t g_rgctx_Iterator_1_t401B0AE4A7AE625421285FB386F87D7EB1213E82;
extern const uint32_t g_rgctx_Iterator_1_Dispose_m3973A9258B5A77E6B3F7DC3D004466E6296075A9;
extern const uint32_t g_rgctx_Enumerable_CombinePredicates_TisTSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A_m457636321FF5773C76C14EA990DF6EBA3827FA1C;
extern const uint32_t g_rgctx_WhereSelectArrayIterator_2_t6BD47364FC721CA8B09BDFC7BE6810CCE818F41E;
extern const uint32_t g_rgctx_WhereSelectArrayIterator_2__ctor_m13925FA98D8607D9EA9B1A4792AE6A94B2849DF1;
extern const uint32_t g_rgctx_Iterator_1__ctor_m474A63CD9FAA51728C0378997DDC4C8B5FE28303;
extern const uint32_t g_rgctx_Iterator_1_t4928FCA7FD6F8CA3BFB0698285A34D6BBDE1A112;
extern const uint32_t g_rgctx_WhereListIterator_1_t39045FEC3E9F1D32C0EA2780668C61E302992807;
extern const uint32_t g_rgctx_WhereListIterator_1__ctor_m172443247095E67B21AF11E2907D7B644EB793DE;
extern const uint32_t g_rgctx_List_1_t65D73AE3589A56A7B32F4BDFCD91269AD04DD4DF;
extern const uint32_t g_rgctx_List_1_GetEnumerator_m62042CED4A1CF9B02B5E17694405BBB8BEEDD38C;
extern const uint32_t g_rgctx_Enumerator_get_Current_m21D84BB0301B459F1ADE9ABD50089FBBB8C63F97;
extern const uint32_t g_rgctx_Enumerator_t8E62FE91E95BFC5D28A3B09EFA69C2A33120205E;
extern const uint32_t g_rgctx_Func_2_tC858B64F5B124B5C1F30E774832D4E614DA18793;
extern const uint32_t g_rgctx_Func_2_Invoke_m1C2F1F284152F67D5FE0FD1BD2D71BD3E2DD280F;
extern const uint32_t g_rgctx_Enumerator_MoveNext_m1A9C394EDBEE8ABF55FA1F44A260F79D813902E4;
extern const uint32_t g_rgctx_Iterator_1_t4928FCA7FD6F8CA3BFB0698285A34D6BBDE1A112;
extern const uint32_t g_rgctx_Iterator_1_Dispose_m84B51BBBD674EB42CD5E238D01DC427248C5043F;
extern const uint32_t g_rgctx_Enumerable_CombinePredicates_TisTSource_t85B7C93A555823AE666813BFFC5FEC432E108956_mEF6DF5A93E207AEA02FF346A380F597872BF6F49;
extern const uint32_t g_rgctx_WhereSelectListIterator_2_tA11FC7FED3C26063A55DAAA599906A1C57175B03;
extern const uint32_t g_rgctx_WhereSelectListIterator_2__ctor_m89A10922BF0309154D097D4D7E630E8451C1B952;
extern const uint32_t g_rgctx_Iterator_1__ctor_m24F4541F8829F51E57F84D96054E563391732CFC;
extern const uint32_t g_rgctx_Iterator_1_tA31D49CCC35E12E44AB58CA8F1ABB8B79289764F;
extern const uint32_t g_rgctx_WhereSelectEnumerableIterator_2_t48BC8AE4F3D8AE2BB3FB23C3AFC140A756CC65A4;
extern const uint32_t g_rgctx_WhereSelectEnumerableIterator_2__ctor_mDA7AA133551DE9DAA42B9489EF99A53B6BF80749;
extern const uint32_t g_rgctx_Iterator_1_Dispose_mEC8779D213FB3A1CF689B52F5B8219238E54A57B;
extern const uint32_t g_rgctx_IEnumerable_1_tA64D266802CC654E58E383563C59E5BC49B1AD22;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_m8A5C078C211D763A5213D0930EBD38A3D97EA825;
extern const uint32_t g_rgctx_IEnumerator_1_t01303709A68F833425B5740A2A2D972A0DDEEB26;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_mFE78B9CDC5BBDF50E78AFAD9CFE23F2223C79F5B;
extern const uint32_t g_rgctx_Func_2_t86CFE648CE7192981F7DA895E30FBDA1F513B652;
extern const uint32_t g_rgctx_Func_2_Invoke_m4148D75120CEABE2FF0024661FDDBFCB6BA771A5;
extern const uint32_t g_rgctx_Func_2_tD5EAA29CDB4313FE2590F76DD99FB1497FF215B1;
extern const uint32_t g_rgctx_Func_2_Invoke_m76A5030A28A4F68091A624D3302941DB8B4E0765;
extern const uint32_t g_rgctx_Iterator_1_tA31D49CCC35E12E44AB58CA8F1ABB8B79289764F;
extern const uint32_t g_rgctx_WhereEnumerableIterator_1_t46D8F3B462050CB986339EA63B34443BA66D5EE9;
extern const uint32_t g_rgctx_WhereEnumerableIterator_1__ctor_m05CA91B0739729D9DFB15FD9AE29358281C4DF95;
extern const uint32_t g_rgctx_Enumerable_CombineSelectors_TisTSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093_TisTResult_t33CDF94D13BEBA6908E84F958D63A95F7466E520_TisTResult2_tACCDF53F8D9C783083BE76E1EBF4F0851CBEA20C_mF0413C490C865332533AAD91E5E31905E989A32D;
extern const uint32_t g_rgctx_WhereSelectEnumerableIterator_2_t091A81B2BFDECBB6B85A5DE344E32E306B979F4E;
extern const uint32_t g_rgctx_WhereSelectEnumerableIterator_2__ctor_mF714167A39020832C4835CAA8F81F6E0FAA9A789;
extern const uint32_t g_rgctx_Iterator_1__ctor_m6A1E7CB836C19C0B9439096586A06D0057E7AA52;
extern const uint32_t g_rgctx_Iterator_1_tEE17D73E1A34A4CF384B00C3E896D8BCCA8406C7;
extern const uint32_t g_rgctx_WhereSelectArrayIterator_2_t2F5234271A3A4E5F89C63030DD6F9D9260D06FDE;
extern const uint32_t g_rgctx_WhereSelectArrayIterator_2__ctor_mCD9A624F8C3ACA086CFD4CEBB6150456E1471C9B;
extern const uint32_t g_rgctx_Func_2_t47CC59E1937CA3FCC9DA471AAD5C7899D9AFF9DF;
extern const uint32_t g_rgctx_Func_2_Invoke_m8DAC2E225A682443964FAEA00BE2C728AAD74B0D;
extern const uint32_t g_rgctx_Func_2_t8A5A56224271942180907637F3E10A9A3CBDAEDF;
extern const uint32_t g_rgctx_Func_2_Invoke_mFA2E82CEFB4B24BDB33564DECDF4765D2B7C7053;
extern const uint32_t g_rgctx_Iterator_1_tEE17D73E1A34A4CF384B00C3E896D8BCCA8406C7;
extern const uint32_t g_rgctx_Iterator_1_Dispose_mA9BFBEB710778B3A052F66CEDA033562C82E1D71;
extern const uint32_t g_rgctx_WhereEnumerableIterator_1_tC18F5A6D2AF40216AE21EBC6827AD147E31E17A5;
extern const uint32_t g_rgctx_WhereEnumerableIterator_1__ctor_mA5B3E7EB5B0FFE980FA8EE42233961A20AC087F7;
extern const uint32_t g_rgctx_Enumerable_CombineSelectors_TisTSource_t21BF09076F270DC063711DE3ABB52B001A331F78_TisTResult_t278B55150BC17BB45D33B605F011F4D96EFE5425_TisTResult2_tEC28CE9F47F4F949C7CD44736D7F4B15360A65F9_m5CAC93D4ECC6772D64346C0581C436601A3E07B1;
extern const uint32_t g_rgctx_WhereSelectArrayIterator_2_t59D43E919F2DC1D758D7C811297A1435D53D93AC;
extern const uint32_t g_rgctx_WhereSelectArrayIterator_2__ctor_m1F6E197D75A7ECC536CF790E45D8855D46A1FDC6;
extern const uint32_t g_rgctx_Iterator_1__ctor_mAB5D6B06319C192633E05B6EBBA9A168FF73AAE9;
extern const uint32_t g_rgctx_Iterator_1_t908D71005972796790D5ED7033CA7098F2134EEF;
extern const uint32_t g_rgctx_WhereSelectListIterator_2_tBA41BFF0DB2BFE973868036026CDCA6B8797A8D6;
extern const uint32_t g_rgctx_WhereSelectListIterator_2__ctor_mDFE79323B2924E6309386ABFB7F9AE7BAAD059C2;
extern const uint32_t g_rgctx_List_1_t905EFEC983EC5317F0B1F633D205BF984BB0BE1D;
extern const uint32_t g_rgctx_List_1_GetEnumerator_m906D8353E6DC2D62B1C6ACF3849D1970361C7AED;
extern const uint32_t g_rgctx_Enumerator_get_Current_mEB276D052415C98826154DC4FDF8574C48E0FAF0;
extern const uint32_t g_rgctx_Enumerator_t8A622325AF1352D3AB0ECDBB45A0AFB7AF959716;
extern const uint32_t g_rgctx_Func_2_tBE76289600B0D10382BAB5D9F828D996195A6D07;
extern const uint32_t g_rgctx_Func_2_Invoke_mF94AE9E660C674B47621BAB249E8B2D27BF85E73;
extern const uint32_t g_rgctx_Func_2_tC25DAB584B0F47C1DAA1B56A2C30A3D42B88D146;
extern const uint32_t g_rgctx_Func_2_Invoke_m74CA45C07863967094098CE16E020CA52859B1D3;
extern const uint32_t g_rgctx_Enumerator_MoveNext_mD3BAB36AFD8333EB35A46C14C441E1B1A7493CED;
extern const uint32_t g_rgctx_Iterator_1_t908D71005972796790D5ED7033CA7098F2134EEF;
extern const uint32_t g_rgctx_Iterator_1_Dispose_m741197394517AA91B94A9D65A084BBAED71C3C3A;
extern const uint32_t g_rgctx_WhereEnumerableIterator_1_t957AB458B1F7D316B1F8960AE854A6CD7E1DD852;
extern const uint32_t g_rgctx_WhereEnumerableIterator_1__ctor_mF25AEB188FA18B82EFB71A5BAD8534E8A1FFCEE2;
extern const uint32_t g_rgctx_Enumerable_CombineSelectors_TisTSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3_TisTResult_t11AC9139084FDCB528CAF75FE5166467D3329A05_TisTResult2_tECB8FBA56F78B893A9D06A35F011858B7CE2F3E3_m0C731C937555DEE92384A692B1DBACCBB7BE7740;
extern const uint32_t g_rgctx_WhereSelectListIterator_2_t8C5A1568CD9B2B2E7760D591DD3A4517DB930770;
extern const uint32_t g_rgctx_WhereSelectListIterator_2__ctor_m43F52D624D5D5CFF28C6B99849AC99EBE6E71A4F;
extern const uint32_t g_rgctx_Func_2_t756BE45FD1B4569EBD49EAD2AB1444B766D13F83;
extern const uint32_t g_rgctx_Func_2_Invoke_mE7A8E49A025849A2FE64A86343365C1808AD743F;
extern const uint32_t g_rgctx_Func_2_tE17298D4C6D18DE4FB73F421AF563BE9FB9630EB;
extern const uint32_t g_rgctx_Func_2_Invoke_m176EFBF601E4DFA96422134D1F9C9A90B94D6ACF;
extern const uint32_t g_rgctx_Func_2_tB89E2A0A82E89B19927B092B238720F65A87EBE4;
extern const uint32_t g_rgctx_Func_2_Invoke_mE58690AB3F029696906A136F1FFDCB60D54D4C85;
extern const uint32_t g_rgctx_U3CSelectManyIteratorU3Ed__17_2_U3CU3Em__Finally2_mF728E3C6B29EA0DF10D3BA06045AD22644EA3E9B;
extern const uint32_t g_rgctx_U3CSelectManyIteratorU3Ed__17_2_U3CU3Em__Finally1_m3F705537F51F06056319F653E2259BB61FDFC84F;
extern const uint32_t g_rgctx_IEnumerable_1_tD1389C38D56436639122F61396C8E429889C377A;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_m8C99896D8A616F86338CC80E782077A0E16AF4F1;
extern const uint32_t g_rgctx_IEnumerator_1_tFD0011EBB450CC3BF27CEC691ECB0C3AECC7749F;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m6140A669FD20F62976EC9AD7ABC81919CD1D766F;
extern const uint32_t g_rgctx_Func_2_t613FB799F1283E17E4BF8D5FE514CD5881BA76C1;
extern const uint32_t g_rgctx_Func_2_Invoke_m8DF7C3A537A90832C0824CE33EF2FEBE066C6A41;
extern const uint32_t g_rgctx_IEnumerable_1_tC9F000960A1A3A72A5A8918F1119FCF380D4E487;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_m04A4AE5BFD2F48213FF247D36BBE7E18877F921F;
extern const uint32_t g_rgctx_IEnumerator_1_tE098A91CD077E31FC61135B5029A16072F2C0FAC;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_mA70C959D540989A08393DCCB40FC89064E6EE422;
extern const uint32_t g_rgctx_U3CSelectManyIteratorU3Ed__17_2_System_IDisposable_Dispose_m4F9011CE53A860AD076D2E84B4D9A628DFE8EF34;
extern const uint32_t g_rgctx_TResult_t35BDCF3171C0EE725B7DC1042A0653542D1C8B80;
extern const uint32_t g_rgctx_U3CSelectManyIteratorU3Ed__17_2_t80F0A8E8CD72F862C9756B513CA0E69CA552C0D1;
extern const uint32_t g_rgctx_U3CSelectManyIteratorU3Ed__17_2__ctor_mA4E3202CDBBD9520C0E219EEBA20CBE5B69ECDA8;
extern const uint32_t g_rgctx_U3CSelectManyIteratorU3Ed__17_2_System_Collections_Generic_IEnumerableU3CTResultU3E_GetEnumerator_m08198DA1542C22E9478C94AE9559F13D8591B212;
extern const uint32_t g_rgctx_U3CTakeIteratorU3Ed__25_1_U3CU3Em__Finally1_m494D6DFFD2769A08E71FCB5268585CE8C4368710;
extern const uint32_t g_rgctx_IEnumerable_1_t741381B26B9B030123F10D94CE5EF70D38CD14DE;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_mAAD097C73F4FE79A08A24E41609D722C02853962;
extern const uint32_t g_rgctx_IEnumerator_1_t6E27CA42389E86E380DD3026EE211BD2D000CCD9;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m62EDABBDED39F332722B912AB74324C8AA619064;
extern const uint32_t g_rgctx_U3CTakeIteratorU3Ed__25_1_System_IDisposable_Dispose_m1315DA05FF75DEB001ACA5957881E651530C754B;
extern const uint32_t g_rgctx_TSource_t02EF8D3CCA7118FDF603FB8654AF79F2FF0F068A;
extern const uint32_t g_rgctx_U3CTakeIteratorU3Ed__25_1_t603726036225D0D95B94BB017D6AABC6E951DE78;
extern const uint32_t g_rgctx_U3CTakeIteratorU3Ed__25_1__ctor_m79C3BF1547D94C46115616E921DE026268EED0A3;
extern const uint32_t g_rgctx_U3CTakeIteratorU3Ed__25_1_System_Collections_Generic_IEnumerableU3CTSourceU3E_GetEnumerator_mE26E1BD6C775B6F1CC0C3CF9A95A0D18EA92C4DF;
extern const uint32_t g_rgctx_U3CDistinctIteratorU3Ed__68_1_U3CU3Em__Finally1_m5A1FD8F557D9372B7207DA439D3F5400A5D680AB;
extern const uint32_t g_rgctx_Set_1_tF01934D2229565F204C9ADF13158DCCB8CCD2EB7;
extern const uint32_t g_rgctx_Set_1__ctor_m815CB40BA85CEF706F531B7BF439E4D505BB5E42;
extern const uint32_t g_rgctx_IEnumerable_1_t43811822819B75BE6619279ABA5B08ADD11A36C6;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_mAFA75F0FA4A7759C4ECC79C7F42CE043C0BBE463;
extern const uint32_t g_rgctx_IEnumerator_1_t2A2E2EF21339FD112C964B9CF2654AA9BAE4F2CA;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_mEE747CACD72C9E1BBB4DB60B37811664ED7DC536;
extern const uint32_t g_rgctx_Set_1_Add_m7DC65238C38BBB6ADCC867FD478D64A4338BA366;
extern const uint32_t g_rgctx_U3CDistinctIteratorU3Ed__68_1_System_IDisposable_Dispose_mE5F9EBDAF6CE2E21979B6940EA37E5544C7DFF27;
extern const uint32_t g_rgctx_TSource_t3FF79E3F222559BCCBA35ED008F0F85B66E62A00;
extern const uint32_t g_rgctx_U3CDistinctIteratorU3Ed__68_1_t9F1140F3B4BD52639A46DEAC9764A78092C97305;
extern const uint32_t g_rgctx_U3CDistinctIteratorU3Ed__68_1__ctor_m412D5949A71FB2DF622581177F22A884DDC67287;
extern const uint32_t g_rgctx_U3CDistinctIteratorU3Ed__68_1_System_Collections_Generic_IEnumerableU3CTSourceU3E_GetEnumerator_mBE8DC2773FB7231E662A140F2047ECA0B63D6879;
extern const uint32_t g_rgctx_U3CExceptIteratorU3Ed__77_1_U3CU3Em__Finally1_mACA5CC35C36BCCC30B81B26C8E0B555C3DFF906A;
extern const uint32_t g_rgctx_Set_1_tC97E83E279EA20D849DD344BAD2B918EEE71896A;
extern const uint32_t g_rgctx_Set_1__ctor_m992E04FD43623CA91D67886AD1EA9C6FE2DDD100;
extern const uint32_t g_rgctx_IEnumerable_1_t3C9331E70299CEDFA221B9358DCA46615CDAD471;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_m7AC9B87A0C94E96D3D2A56B4D9686E9671048A95;
extern const uint32_t g_rgctx_IEnumerator_1_t510E4AD6C23F76BD0971C744CE12085C1A2057F3;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m8806160817B932495F753E1C2D1138991CD16BCA;
extern const uint32_t g_rgctx_Set_1_Add_m59B7D39F64711E39511E5F279ED1F1C77570DADF;
extern const uint32_t g_rgctx_U3CExceptIteratorU3Ed__77_1_System_IDisposable_Dispose_m4357E56ADF355A7446F0CFE200BF33171BA67EE2;
extern const uint32_t g_rgctx_TSource_tE967D1BA8CA00781B8F695FA112AD70C48CB6878;
extern const uint32_t g_rgctx_U3CExceptIteratorU3Ed__77_1_t7A68C5D64D78B1068E46396C69CEDFB837178E9E;
extern const uint32_t g_rgctx_U3CExceptIteratorU3Ed__77_1__ctor_m5162331A0E564DCF9EDBBF01855F67BDA43F3CC2;
extern const uint32_t g_rgctx_U3CExceptIteratorU3Ed__77_1_System_Collections_Generic_IEnumerableU3CTSourceU3E_GetEnumerator_mE1D729057481B4E547167276A83BAF8B9BB810C8;
extern const uint32_t g_rgctx_TElementU5BU5D_t5FE845F5AF158D61A1612AC86BF41A482409E218;
extern const uint32_t g_rgctx_EmptyEnumerable_1_t903C1B1D5A3723EB325CD99884D858F929D989D3;
extern const uint32_t g_rgctx_EqualityComparer_1_get_Default_mF9ADBF37046B00B4C61CA959D6EC4A851302041A;
extern const uint32_t g_rgctx_EqualityComparer_1_t3C6F85286B5844659CD99C8CD82F39A1027D0E28;
extern const uint32_t g_rgctx_SlotU5BU5D_t505B87EE9501DF282930D90EBCE91A5A51A6ADB6;
extern const uint32_t g_rgctx_Set_1_Find_m0EE1659DEEEBAB3ECCC1F697BADD51B15F897CB4;
extern const uint32_t g_rgctx_Set_1_InternalGetHashCode_mEB2BF942411714E6D3DF54C3B8C84C81FECF480F;
extern const uint32_t g_rgctx_IEqualityComparer_1_t253FDF060C665D2CAE293B27514148BC04F881E2;
extern const uint32_t g_rgctx_IEqualityComparer_1_Equals_mE91439EC229D29977A94DDFDE430E5512204C1ED;
extern const uint32_t g_rgctx_Set_1_Resize_mC350A354D2354B256A23057B23D4977E4653170F;
extern const uint32_t g_rgctx_TElement_t65838287198D29C1A2F194E4FBD25389CA14586D;
extern const uint32_t g_rgctx_IEqualityComparer_1_GetHashCode_m72FC6D66920C3DFDB7422DCC3D13CE50ED7E24A8;
extern const uint32_t g_rgctx_U3CGetEnumeratorU3Ed__1_t3CC996D75E05583A2C68BDAA6119DD5395C4CAEE;
extern const uint32_t g_rgctx_U3CGetEnumeratorU3Ed__1__ctor_mD3A17D2F3E5D0A469641D57A4AB655B4545F375E;
extern const uint32_t g_rgctx_OrderedEnumerable_1_GetEnumerator_mBBDBE3B4727EE491AF45177AF6A25516F22737D7;
extern const uint32_t g_rgctx_OrderedEnumerable_2_tBEC552CAD99DF0748B3CF3552F93BE83E3A03F3F;
extern const uint32_t g_rgctx_OrderedEnumerable_2__ctor_m8890686A74F81E8473FB5D036EE0D750597D2994;
extern const uint32_t g_rgctx_Buffer_1_t41F8077A5F13608D5270B50E18148B45F5F315C7;
extern const uint32_t g_rgctx_Buffer_1__ctor_mA99E4505CFF1FED56FB8272A49E274F14DBB6727;
extern const uint32_t g_rgctx_OrderedEnumerable_1_t9A3D8D2850455B28D36B701298D0B1331F534031;
extern const uint32_t g_rgctx_OrderedEnumerable_1_GetEnumerableSorter_m5F587D4742CDA03CB231EF0741B98D9EB7EF4E84;
extern const uint32_t g_rgctx_EnumerableSorter_1_tA62734D066C60347DFE7A135B5958DFFCF9E8C51;
extern const uint32_t g_rgctx_EnumerableSorter_1_Sort_m82301704DAE9F05F1C2681B4E735E04BB7919073;
extern const uint32_t g_rgctx_TElement_t7131B4894D970BCE712C2414419F0A27829AF29C;
extern const uint32_t g_rgctx_OrderedEnumerable_1__ctor_m920D35170CC92329CACC9CFB60EF8BB9C06FF9FF;
extern const uint32_t g_rgctx_OrderedEnumerable_1_t06CB3897759B3B58FCFDD71EC11AFB8E99366F94;
extern const uint32_t g_rgctx_Comparer_1_get_Default_m9436BB4B67683FA68956FF78111C7DA24A35FD25;
extern const uint32_t g_rgctx_Comparer_1_t05930316C99AB50EC343359F3B8840EEADD7452B;
extern const uint32_t g_rgctx_EnumerableSorter_2_t8479B5254E2828D3550EA1B532B05EDB1B1215D6;
extern const uint32_t g_rgctx_EnumerableSorter_2__ctor_m18A2FE6C6F5054713B98012F0E2CD0B5DB7C20BE;
extern const uint32_t g_rgctx_OrderedEnumerable_1_t06CB3897759B3B58FCFDD71EC11AFB8E99366F94;
extern const uint32_t g_rgctx_OrderedEnumerable_1_GetEnumerableSorter_m7268D01B139AF537E1343B1EC035A4E3EB18243D;
extern const uint32_t g_rgctx_EnumerableSorter_1_tBB9ADD7C21E31739D9683D99CFF9DC117D8BAB11;
extern const uint32_t g_rgctx_EnumerableSorter_1_ComputeKeys_m0261683B46812CA7A0CEB845C1EF325F8033694E;
extern const uint32_t g_rgctx_EnumerableSorter_1_QuickSort_m01455655602074FD67BC431F21F62F7A9180571C;
extern const uint32_t g_rgctx_EnumerableSorter_1_CompareKeys_mFB513F8D369E5221DD6F66ACC4F34A50807CDBC6;
extern const uint32_t g_rgctx_EnumerableSorter_1__ctor_mFF96BE3E2A79A8BC38E1A650D9434EA57297BF46;
extern const uint32_t g_rgctx_EnumerableSorter_1_t053F2BD859874727D1E461B965976B49B4A173C7;
extern const uint32_t g_rgctx_TKeyU5BU5D_tE5676E72B1BCCA85AD5A6118A3858A2144C86857;
extern const uint32_t g_rgctx_Func_2_t5E10C25103ED51C0C843F4F679CFF099A92D2033;
extern const uint32_t g_rgctx_Func_2_Invoke_m8D38D643551E8034BC2F061748DC2E8A54B8FC99;
extern const uint32_t g_rgctx_EnumerableSorter_1_t053F2BD859874727D1E461B965976B49B4A173C7;
extern const uint32_t g_rgctx_EnumerableSorter_1_ComputeKeys_mFBB6EE61ABB9424BD1DD39936A10EA3D454AF202;
extern const uint32_t g_rgctx_IComparer_1_t1FA8428328A44FE33A3569A2A717B4CC10F6D553;
extern const uint32_t g_rgctx_IComparer_1_Compare_m392095FFDA3D97DA5903FA4F1CCEE94E1CA1E5BA;
extern const uint32_t g_rgctx_EnumerableSorter_1_CompareKeys_mA39249DC095B5EC415BF70815665F8483E6229D6;
extern const uint32_t g_rgctx_ICollection_1_tB92B34A134CB1BF586A69F2A283CF79675A37E1D;
extern const uint32_t g_rgctx_ICollection_1_get_Count_m853E49D009E94914082E87AD16E91AD4A7694DEE;
extern const uint32_t g_rgctx_TElementU5BU5D_t65424EAA6380C3A80C7FCEBE88D5E248445EFD15;
extern const uint32_t g_rgctx_ICollection_1_CopyTo_m1623FBCB4E13BACF6CA953F8F38FD10B4ABDC6C9;
extern const uint32_t g_rgctx_IEnumerable_1_t03135CC19B082BC866CC79592745590E608D5CE4;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_mD5E0E805DDE55F5756E21D0D5FEDB2220FA39060;
extern const uint32_t g_rgctx_IEnumerator_1_t13EFC35CCC3C9F302141EE5C116481E1CF2CDC48;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m1BB68E9CA48B668E739FD9AF759EEE794E0CC7A5;
extern const uint32_t g_rgctx_Dictionary_2_t6D06D4E5F7D25D56B6A19114BD410EF7C1C8EEA2;
extern const uint32_t g_rgctx_Dictionary_2__ctor_mA3368FADA46D2FDD7428CC536AFDE4C19B13566E;
extern const uint32_t g_rgctx_Dictionary_2_Add_mCF74069775EA16349F780044744CAC6EC238E676;
extern const uint32_t g_rgctx_Dictionary_2_TryGetValue_m67E55BB9DBE7FAE34B406D048D0703B26806DE65;
extern const uint32_t g_rgctx_Dictionary_2_get_Count_m6B4D3CEE28B6F7E6220C9A0E41A7733593A7E9F2;
extern const uint32_t g_rgctx_IEnumerable_1_tD1F5957398D4DB123961818284415FBE534BC22A;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_m79AC5FCCE7F0D4D2BACD98F05A3F9F0CD85BE410;
extern const uint32_t g_rgctx_IEnumerator_1_t71282494681DD34DFA6390FBAD52FED29986855E;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m05021FC24229AA1EDAA31B2C322380C83965C5AE;
extern const uint32_t g_rgctx_IReadOnlyCollection_1_t643AA0DE2BD19AF4360D7AAAD04DE5D6F8472ED4;
extern const uint32_t g_rgctx_IReadOnlyCollection_1_get_Count_m50B71DE8246F5B1338CD8E5BE3EF8102FFEBA343;
extern const uint32_t g_rgctx_Action_1_t18FBEFC0DF729459650EE8BC850E8423F348794F;
extern const uint32_t g_rgctx_Action_1_Invoke_mDF3038D2095CCE9649DAADE5466CD69E954FCD89;
extern const uint32_t g_rgctx_CacheDict_2_AlignSize_m44DAB39A428C07B7887289D3B26CC228C4F90E72;
extern const uint32_t g_rgctx_CacheDict_2_t656AB3D5CCFCBC43AE10036192190A1EE1EE9A5E;
extern const uint32_t g_rgctx_EntryU5BU5D_t0A8C6A83EA4B5CE761F205824E8C6FF9FB255ADD;
extern const uint32_t g_rgctx_TKey_tB5D0C0709F7D188CFFC5CCAA6B565FC07556B3FE;
extern const Il2CppRGCTXConstrainedData g_rgctx_TKey_tB5D0C0709F7D188CFFC5CCAA6B565FC07556B3FE_Object_GetHashCode_m372C5A7AB16CAC13307C11C4256D706CE57E090C;
extern const Il2CppRGCTXConstrainedData g_rgctx_TKey_tB5D0C0709F7D188CFFC5CCAA6B565FC07556B3FE_Object_Equals_m07105C4585D3FE204F2A80D58523D001DC43F63B;
extern const uint32_t g_rgctx_Entry_tB6EBBB0269749705EFC7FCB0B768B4F45CB7FC63;
extern const uint32_t g_rgctx_Entry__ctor_m9750D60F6EB3DC46DB0642B51C0150979A873A22;
extern const uint32_t g_rgctx_CacheDict_2_Add_mCC2EF29D9ADDB74392FFBD05E20BE780327E0938;
extern const uint32_t g_rgctx_EqualityComparer_1_get_Default_mC93F859DDE3938407D49FF1E5A96CED45C316265;
extern const uint32_t g_rgctx_EqualityComparer_1_tA96567156D027DA41596C9CA1C5DEAB0CDEE6C60;
extern const uint32_t g_rgctx_HashSet_1__ctor_m781AB04365DCD9333E443C412DFFE8102DCAA2D0;
extern const uint32_t g_rgctx_HashSet_1__ctor_m07CC1E138E0D451EA7ED1AC941AC1245011C2093;
extern const uint32_t g_rgctx_HashSet_1_tF089CA52CB584DB29B4FF68C4A59B7C5FBD3630A;
extern const uint32_t g_rgctx_HashSet_1_AreEqualityComparersEqual_m0E95D8BA36E2A85337C69FE839358C53D874D82C;
extern const uint32_t g_rgctx_HashSet_1_tF089CA52CB584DB29B4FF68C4A59B7C5FBD3630A;
extern const uint32_t g_rgctx_HashSet_1_CopyFrom_mF3114EC5E22390EB6044B5BB4731BE3733A2AACA;
extern const uint32_t g_rgctx_ICollection_1_t0962A9980803A8F46108387826B91CD4DB9B0F97;
extern const uint32_t g_rgctx_ICollection_1_get_Count_mC4059B0C3219EDC8E97DE3ECFF2B0A4A0280801E;
extern const uint32_t g_rgctx_HashSet_1_Initialize_m06C4A2DE0A243BB8A2D0C4345712ED9B91231993;
extern const uint32_t g_rgctx_HashSet_1_UnionWith_m630B15B252A9518ACDC7F2CC33E343AF51C014B1;
extern const uint32_t g_rgctx_HashSet_1_TrimExcess_m772030970D2E00DEA17364C4A8633644B366DE11;
extern const uint32_t g_rgctx_SlotU5BU5D_tCF3C9EE13C54F730A642AD5F260A5A7D2F9F73F7;
extern const uint32_t g_rgctx_HashSet_1_AddValue_m1539D2475B8B90B247ED5A3C4E01698DF6D74F19;
extern const uint32_t g_rgctx_HashSet_1_AddIfNotPresent_mF89D8C4E328F141B43BA304A67EFAE78CF643968;
extern const uint32_t g_rgctx_HashSet_1_InternalGetHashCode_m175DF882B346A324B102A8692CA09758B465DF72;
extern const uint32_t g_rgctx_IEqualityComparer_1_t66DFFD1D981BA05FF20035307F86BFC3864B2E2B;
extern const uint32_t g_rgctx_IEqualityComparer_1_Equals_m0539178A3A28082426D3792F170D842E3F99CCA6;
extern const uint32_t g_rgctx_HashSet_1_CopyTo_mAC8E7BAAD9DE7ECC11D9FC60E3A4FBD661B4A329;
extern const uint32_t g_rgctx_Enumerator_t45B9839DDB003D337DAD360EE2D7537B7E8F9F2D;
extern const uint32_t g_rgctx_Enumerator__ctor_m757B4624317C66B0082A97D86F44F4732370B396;
extern const uint32_t g_rgctx_IComparer_1_t6BC8594DB26FCC0B360DE8C22BD01836BA24C8AC;
extern const uint32_t g_rgctx_TU5BU5D_t6BCCEA57BEA1E43097B80E2965A5789452F93BA0;
extern const uint32_t g_rgctx_HashSet_1_CopyTo_m636F301EC0DFB1B2F58553B0EE2E5D4B41B02261;
extern const uint32_t g_rgctx_TU5BU5D_t6BCCEA57BEA1E43097B80E2965A5789452F93BA0;
extern const uint32_t g_rgctx_IEqualityComparer_1_t66DFFD1D981BA05FF20035307F86BFC3864B2E2B;
extern const uint32_t g_rgctx_SlotU5BU5D_tCF3C9EE13C54F730A642AD5F260A5A7D2F9F73F7;
extern const uint32_t g_rgctx_TU5BU5D_t6BCCEA57BEA1E43097B80E2965A5789452F93BA0;
extern const uint32_t g_rgctx_IEnumerable_1_t08DFCA249A6163529549D46ACA84A83C8CD361EC;
extern const uint32_t g_rgctx_IEnumerable_1_GetEnumerator_mD059A216A04E59863006CEE9F7C3BD8AA41F1D5C;
extern const uint32_t g_rgctx_IEnumerator_1_t1BD2EC88A1B4550751DED0BBB53571254F37887A;
extern const uint32_t g_rgctx_IEnumerator_1_get_Current_m149653A74BD91288C695A04557C5D768E16EA745;
extern const uint32_t g_rgctx_HashSet_1_Clear_mBCB831BE78A9259AAEFB3051763BAE40121F9D11;
extern const uint32_t g_rgctx_HashSet_1_IntersectWithHashSetWithSameEC_m44EC438AB13789AE47C1FE321760937D6B93586F;
extern const uint32_t g_rgctx_HashSet_1_IntersectWithEnumerable_m7A0EB45FE7BD56851D687DBFA37C331E4CE25E77;
extern const uint32_t g_rgctx_HashSet_1_Remove_mFD3EA80DFC96201A988DBFBD52A4F920AFB5384D;
extern const uint32_t g_rgctx_HashSet_1_SymmetricExceptWithUniqueHashSet_mD194BE9E68BDFEEAC21CC0AEF0A29B09B0AE16B7;
extern const uint32_t g_rgctx_HashSet_1_SymmetricExceptWithEnumerable_m8B945926110C56656B148F3F7A52ED0DB7894DE3;
extern const uint32_t g_rgctx_HashSet_1_get_Count_mF76AC662D895CC68C20E848F79874EAB1A79DA31;
extern const uint32_t g_rgctx_HashSet_1_IsSubsetOfHashSetWithSameEC_m9E35091BBA5F31F05AAD8A0E2C2EBA07AC600E6A;
extern const uint32_t g_rgctx_HashSet_1_CheckUniqueAndUnfoundElements_mEA361D87EEB7BAD67D2F3CE429595DEFA932A5DE;
extern const uint32_t g_rgctx_HashSet_1_ContainsAllElements_mCF6E110D72174582EF10330832B7D5A28D3183F0;
extern const uint32_t g_rgctx_HashSet_1_Contains_m9FC46B9B95724A3C501B1AB2A623A4DDEE540ED3;
extern const uint32_t g_rgctx_Predicate_1_t1F12E2E3D79CAB6F034E6063432D655A79E0C690;
extern const uint32_t g_rgctx_Predicate_1_Invoke_m1E90162EC37F65593DEE945DFC92BA7B4259B3B7;
extern const uint32_t g_rgctx_HashSet_1_SetCapacity_mBAE6B90A5CE1BD75B08B8527763700172A4ADB69;
extern const uint32_t g_rgctx_HashSet_1_IncreaseCapacity_mC430EB8352A6B45A9776BF3373EEE6551FC85ABE;
extern const uint32_t g_rgctx_HashSet_1_GetEnumerator_m477CCED045EA6DDD1DD1A3EB43BC20397E889D37;
extern const uint32_t g_rgctx_Enumerator_get_Current_mDAB434264D5F378E41D5E46055A8797685BD2A3B;
extern const uint32_t g_rgctx_Enumerator_t45B9839DDB003D337DAD360EE2D7537B7E8F9F2D;
extern const uint32_t g_rgctx_Enumerator_MoveNext_m8945184F458AB61968C5BCB26E20FAD91B6114D1;
extern const Il2CppRGCTXConstrainedData g_rgctx_Enumerator_t45B9839DDB003D337DAD360EE2D7537B7E8F9F2D_IDisposable_Dispose_m3C902735BE731EE30AC1185E7AEF6ACE7A9D9CC7;
extern const uint32_t g_rgctx_HashSet_1_InternalIndexOf_m2D447E428750224983163A2C527019856AFDBFBC;
extern const uint32_t g_rgctx_HashSet_1_AddOrGetLocation_mAE6A7B28983C117BB3D9C8C21448236DF99B922A;
extern const uint32_t g_rgctx_HashSet_1_get_Comparer_m313EEB5FFD720AD1F35ABB61097076D8ABE48A73;
extern const uint32_t g_rgctx_T_t1A61667A2FF6D68BB3DAC186281F928B7ED2DB94;
extern const uint32_t g_rgctx_IEqualityComparer_1_GetHashCode_mB43AB2E622EB30D675693CDC96CA5D836DE43336;
extern const uint32_t g_rgctx_Enumerator_get_Current_m6F22509C5AEA1EA15942F7F9C9866256CB3EA347;
extern const uint32_t g_rgctx_Enumerator_tB091A59F0E047A76EF2099D441944326FE3C0B97;
extern const uint32_t g_rgctx_T_t6D22409F37413B725563BF484486F55FB7202BB8;
extern const uint32_t g_rgctx_ICollection_1_tFEFB414626FD111D128FEBCF2B2893D2D1BFA23B;
extern const uint32_t g_rgctx_ICollection_1_get_Count_m59A49BC41F6F347F1A5161D5C655CC8F14B4465C;
extern const uint32_t g_rgctx_TU5BU5D_t7141ABD7B24C6F56B55DB7911E6CE85CAACA4FFF;
extern const uint32_t g_rgctx_ICollection_1_CopyTo_m142EAE547CEB167F8913259B3A9EBEF7718F80AD;
static const Il2CppRGCTXDefinition s_rgctxValues[443] = 
{
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Iterator_1_tAFB7558C92D3848C170203685AA45B10B6035464 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1_Where_mB33345A6D2213AB59B7B357292542E752C9AEEF2 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_TSourceU5BU5D_t5F9558857B1D501A57AAC7DDF5A60A1CAF6A8736 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereArrayIterator_1_t8F188FD6974943DFDC1A3C36E69549C9146DCB25 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereArrayIterator_1__ctor_mFE764A6F32B18EEABDD6813CF733205E2149C7B7 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_List_1_t8601446322D050B44EBF5C49E8048407F11D6239 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereListIterator_1_tDAFC464D33DAF1B893DB760F55638A7AC019AEB9 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereListIterator_1__ctor_m0D87B2EFC00BD5C900E47BED483C334DC731E51D },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereEnumerableIterator_1_tB9885E49C2A0467CBEB9B331919AE76488DD4BA8 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereEnumerableIterator_1__ctor_m7CA177F283ABFD6426F57A5630315F53267741CE },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Iterator_1_t83549F4A854FAE4651C92A7B3B8907E4798F0121 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1_Select_TisTResult_tF3AC1D6143237427ECB7A483D967C1FE5374DBD7_mC9EEBF5649EB6F682C5621B1AF6786BFFC2C62B4 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_TSourceU5BU5D_tD0F38A3B04FEF1F6EB6A2C0F97C2F6826A3C1198 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereSelectArrayIterator_2_tD31A5253F7EAAB16463FB95C4B1DF1B5BA0BE6DE },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereSelectArrayIterator_2__ctor_m85B91DA1F46361240445ADE95E0CFD6F1674C1FA },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_List_1_t7FCC2F8DB1446378C6AD15E4C2ECDCB8E2001280 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereSelectListIterator_2_tE91BB456A01CEF4F6BC613FDF4A44F341B2D7206 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereSelectListIterator_2__ctor_m0D002693B7EAB5A831D2058278463032864687DC },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereSelectEnumerableIterator_2_t9583448D4FAA842B0C18940E2557F5D5A9507364 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereSelectEnumerableIterator_2__ctor_m8F12E12FDDE5F7E663BA04C6B41490D162423694 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_U3CU3Ec__DisplayClass6_0_1_t0D7DCEEA7C4415169B2CBD5801DECF1AE6BC71D1 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CU3Ec__DisplayClass6_0_1__ctor_mC075FAA755826D869270E4A74AED806B91B2E5F3 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CU3Ec__DisplayClass6_0_1_U3CCombinePredicatesU3Eb__0_m6F0EDB0FF04C8A3C9C6D97800722D1B3851C415C },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_t39F15D2C4961B652B7F6B0AD725F37F96D8C9F54 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2__ctor_m18DE7FE4BDFFE701174935655A7EFBA6D405ACA1 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_U3CU3Ec__DisplayClass7_0_3_tCCDD433A1A5065F08529A9FCE5D0C53B52F7B3A6 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CU3Ec__DisplayClass7_0_3__ctor_m248BC6F9C9006A172D95E4482735B14F94409558 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CU3Ec__DisplayClass7_0_3_U3CCombineSelectorsU3Eb__0_mEFA4E2467394FB8379F3CCA7A61136C96768B2BD },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_t09635D19844B1DE3B9DF944B0517FBF783EA917C },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2__ctor_mB0725395805DF6905CB0FAA6BB81FFAAB17AEA93 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerable_SelectManyIterator_TisTSource_t4F1C6525D7158568B966831E7E458E67ED1E17D1_TisTResult_t9FFE0CF4D9F15D47CE62F5B4E43A1576839D17F7_mCEA61666E9C42D2C3C1990FE4AE94726B960FC29 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_U3CSelectManyIteratorU3Ed__17_2_t3E6366BB538F1DDBAE53C058F82E7732A67C1066 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CSelectManyIteratorU3Ed__17_2__ctor_m41401D6425C84176DD5D979BD2B4ACBD3C62A542 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerable_TakeIterator_TisTSource_t9A3EEA082DFE478BD5E5693EF0D5A2543F9F41A3_mBC464106C0C176599F4DE02CB48B29E8516FDACB },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_U3CTakeIteratorU3Ed__25_1_tED8E1AA891BB8AFFD61E1A2A2929C7912E8C663C },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CTakeIteratorU3Ed__25_1__ctor_mB3FBA9A03B2188F6A1C0BC47507EB4D52B48395B },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_OrderedEnumerable_2_t593988007A2B423D75C1D30199B61D4C7E6A838D },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_OrderedEnumerable_2__ctor_m31764352760D7E1ADB9FCFFEC381B7F59B0EA831 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IOrderedEnumerable_1_tE159F36B861ADE6AFF40DE4B62A460AAD3A98102 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IOrderedEnumerable_1_CreateOrderedEnumerable_TisTKey_tE566BC5F30D586A72EF9066D4835B59020C31C7D_m7464B73CF6332FE45471C72ECF4BB249382F0D01 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerable_DistinctIterator_TisTSource_tE445F62DD15B96508EDA86F1C195536B774FFCDB_mFC41AF9DA3F7002B250E5752FE1C3033143A6D53 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_U3CDistinctIteratorU3Ed__68_1_tCD5DF5274B93EE83954ACF81FB8F2A5A79995FC6 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CDistinctIteratorU3Ed__68_1__ctor_mD7880E661DDCD3F4927263534778E64836BF91B5 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerable_ExceptIterator_TisTSource_tE9A48CA2F9C4A502E7DEE0AE573A761AD7F91610_m3711A9E44BFD307B537F0CDE516D45E257735AFE },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_U3CExceptIteratorU3Ed__77_1_t36E5C349AEBF5ED105A39E7C4C601C4D1D3DE265 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CExceptIteratorU3Ed__77_1__ctor_m3C3A0993FD6D96CD86F2F451EAB73EEE1279BAFE },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Buffer_1_tC3AA32816753DA7B0898D92E15B122AC7DE23B5B },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Buffer_1__ctor_m72F00609851E22DF4338204A2E6EC7E3A3E0C3D4 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Buffer_1_ToArray_m11DBDA9AA16C64F60D134E59D6BD79D515B8D187 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Buffer_1_tC3AA32816753DA7B0898D92E15B122AC7DE23B5B },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_List_1_t168E1771B2C2914F0DF873822B754BD4110D6958 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_List_1__ctor_mB51694A9EF5013F0A729FC4B8BD80C8A49970CF9 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerable_ToDictionary_TisTSource_tE31865679B90EA41B3B599272398AC4F59C84AFB_TisTKey_tD37952AE661C99DC819D1D703910E923C1FFB563_TisTElement_tC983FBB6789A209AE3741CF7BF97B4518033512E_m581C4145E7A359AB48C48EF4B9FD323449456C1D },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Dictionary_2_t1E70F86BEBC0F1C830579FA6851930E77390E72B },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Dictionary_2__ctor_m591886154E017552D886FC19F4060A03FE424C93 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_t5A5C0F89267F3218FAA546F66CD24FEBC7CF84FE },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_mC69AE1ABEA30DF65F14B814D77CAD7C4024E22AB },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_tA355CC98E7C1D7ECE78348B13D33CEB831BD17DA },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m50E35714CF970F9143E42B9AEC7B1D77888FC1CA },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_t5C04A674024FA30035DFC9782FFCAAA61F83788A },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_m0D96BC3A9C1650762AC39C6C5FD483FA60F189DC },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_t9712D21F02586859B9C521A9A7AF2CF8C070DC73 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_m11C7E19C8CA2288F9AE5440999F048A468CD4306 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Dictionary_2_Add_m008084EDBF8D30C4C632AB28252CC7E324244C92 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IList_1_tCAFCEB62CA7831D3FFCB2DFACB78E4C973717F78 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_ICollection_1_t8CAB264343D22D2CB6FA36EE9AA77A7CF44564DF },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_ICollection_1_get_Count_m6FA9927538603E9871B9CA77850D733C7610CB02 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IList_1_get_Item_m2A90B8AB52829539BE0F4B737E002A062E1CDF65 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_t4E8307BBC992748AA0EE487FDBC0CA86B913A8BA },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_m475176D6069044687168BCA62AB037C5AA651FD9 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_t2193CA070A1787F1B1F6BB1E9AB6B209B0028101 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m5DEE1F7FC115E516EC4DC694684D55E2DB387B46 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IList_1_t999E2CCC8893878243576C8C48CDECDDB4CC6138 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_ICollection_1_tA93A91F56AB2951AE596AAD0B647F52B66EAA8D9 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_ICollection_1_get_Count_mBD9168EF24E0D1CBFEA0D3FBDFD98C141F75A6A8 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IList_1_get_Item_m01B50E739C1FE86F3F18E308F410D60D2CDC5D82 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_tBACD95C059639CCD92AB1D12E42424080983FB91 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_m1D2DD2E1A7E1C9612293E4B00474A43F3C0849CE },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_tD8DA4BA1989C3A62431320EF709BD2D29BF92FBA },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m167E54B897E90DB0C0B065CD43ED50097BC557F3 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_t4D337022429A25D97A21E2A808E1A7D77670440C },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_m65E2270593D5A2B3086CC4C0795F169F9E185559 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_tCE654AF887B17BAFC80DB8B6DEB165AA340CFE6D },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m14027FFF40999714DAB3619727F42BE99CAB1D64 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_tCD33EA8807153BCC10E860849FE539DFF68675FC },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_m9DD7818B0A1D25B61A09AAB142CF267CA4002398 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IList_1_t67F9D0FF82C6B4EC3D4C75A75CBAD190206293C6 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_ICollection_1_t97C39C344F2B9DC3B3CAB16756748EF4EF38B6B7 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_ICollection_1_get_Count_mF003663592BC97333A81BBAFD7665C7909DDBA5B },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IList_1_get_Item_m66EDBA2B935E97A54009346427D577A753D6A897 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_tA747C8672DA999E3B1FDA618DDEF1C4F8FFB07F0 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_mBD3501BF9140CF73945F0497493A6C3FD504A59B },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_t915DA07A8E8090EBFC5C149A9629615E0EDDA4C0 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m6AE3FC6684B1E871587122CAFA8744A391B247B5 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_t5E257052917A950B3FACC55B8A8A0B49BB974746 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_m1A9475D222D4200965397863EEE4613C6C8A1798 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_t3C7A1094806CE6C8A35132A0CA8BB7989E4C9C18 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_mC0C19BE9C96665D7CE321DEDD26AC6C8643901FE },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_t2CD856C22E0C26253677E18D50FA5D5B15BE1D1B },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_mAA403E7A5C3ABBAB73229A5C25A5E290753BF2A7 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_tEF986F81DB6A3163CFD7CDAA423612D3C77639CC },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_m6FB8D118A5176C69DA8D12EE01C540A380D0CA88 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_t6F6571CF0B132A4B653D0A40A4193F23DEEC3FD9 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m69FFBE7376E424D93345AD43D1E5D533855DA21A },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_t3B2B88FD78F5F69347CF2269307A59AC322C79C3 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_mEB89293A67FE90E3AB9DAD0E7E982413D7D44A4D },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_EmptyEnumerable_1_tF86C133CF22A6B15D25779DC32AC2D2A0163EAEF },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_t87213EF6958E9847E318D7FED68D206925280A0F },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_m623808007A8A20ED9393D48B2467A792BFE9D1D1 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_t34C887C840E86896B486F20B42C0F5EAC90C726E },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_m096D45787935CB3519AA751639FA7C8B7B8058FE },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_tAC8F51D25D6A25E51E41570AD085263B028F5865 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m0CD4A796E3CAD9965C1EDBF2DD175609DBD87C7D },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_tECEEE16E2A7D99CED40251A6F6CA091497F39DF9 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_mCF04C711A970D455B890BDBF34E5ABF28518AE9F },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_t061DE72820C63A06352F98967548DFD6542B40A9 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_m5548A3DF0D5E42E89B2EFCBC06147F8ED3D90E1E },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_t947080FE12F3FB081A1179D1F2EABD2C20A229DB },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m99EBD802C203AAAEF4E8CBEDA3045A4B14FE4013 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_tF3B6C43F69F4FC1146BDB0626C0AF6D2AE612C0B },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_mEBDE43F80162FF3559BC5F1B5F852D549F9B578E },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_ICollection_1_tBDB3D77290C57BA1661C6001A8B5AB96F0ABE3F8 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_ICollection_1_get_Count_m100876A0EFAB4C6F2B30D51C36EB3642A847493F },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_tF77FB81ADA144B654F79BE6C4272CFD3EB0B6299 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_mAF308FC7FBDEB386D13651EFCD80EEB9EE6F3702 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_t8132B77C0BC074307387E78B62BCABC834C87DFB },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_mBDE4817BC08E7BEAAA250EE539FA070F40F2ED43 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_t1BAD868D0DFCFD9BD8C92B590DF72B359A37A15E },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m5A18F62B613EFAE2EE43B2791188C445BD664046 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_t16362D2DFDED0A43A2A5A4EEE13E29A9369B377B },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_m25384294EAEEDBF1541E274BF14CD0BCFA8F3746 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_ICollection_1_t143CB03B088368ACAAEEF662B347A36493BD7F74 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_ICollection_1_Contains_mB272442975A686EF456CFFBE01CEB6E8F6D0FC4E },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerable_Contains_TisTSource_tF5CADD5C21CF2CD60FD685A28FE7C05B80FA6E8D_mE8A1F4CE22DFFE7ED87F9FA0F0A68FBCDBC3D108 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_EqualityComparer_1_get_Default_m70B2467D3FCF463AF4C26D29F891029BF9EC324F },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_EqualityComparer_1_t426D9AC8678417217D095C403FD324D997AB36D4 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_tE136AE95298B0A325F0358D30EBD0A23EA38B301 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_mDA3FB122CDC182176702AA6A1F57FABCD6AD1894 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_t9DF8767078BE055C6FAF64E02370FECE881D6C38 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m552C8A44C35954659B21BF216ADCB1BDADDF7FB0 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEqualityComparer_1_t44B0DD0F5552A29B47C50C45ED1102424C434AFA },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEqualityComparer_1_Equals_mBA41CDA0188EDB9E4464E08B7C9FCE7BD9B6F3A4 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Iterator_1_t8E009DFA0514DB4E4987BB392D13A5A8170ECCE4 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1_Clone_m06A7D1B0BDA308E69987DDED84FFC6B95859AA62 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1_get_Current_m7CDFA0D6C9FE9C1400547F6BDB614EFD06F9BD91 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_TSource_tE11DAFD922BE8DFEB5489CBD1813EB0466BC3D79 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1_GetEnumerator_mF75249EC97644B0005490D15C69E49F7F9164A90 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1__ctor_m690C659CF11A74EED9E70752C5849F1628230AC8 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Iterator_1_t15119AB906B4942B10DE36D501F127F0FF6DF281 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereEnumerableIterator_1_t92EE9D2E5265D8B183ED697686240F506BCA8424 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereEnumerableIterator_1__ctor_m9C038F85EC321BD8F7AE403D683D0153D355F9CB },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1_Dispose_mF10F128ADF4C88061B584756801E3C39F4D04FA6 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_t6BB9BE6EEAECF4E66C19B7781D16F0E830520AC0 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_m844DCC57B48252D74DFA627000935F7B4A4407F6 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_t7057BF629F81E7DFB90FC10A9074D9A504C6971C },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m07F9232B3524F24682301D1CF8573D7A1CB9C6ED },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_tC86143735420E666A856DEA89A154669337AD033 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_m12DE18B02FB8945CB56D98F22BD68442081B02EC },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Iterator_1_t15119AB906B4942B10DE36D501F127F0FF6DF281 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerable_CombinePredicates_TisTSource_tC0EDCBB06D927E5200EDA4B413FCECB2FDD7AFEB_m8E8EBCD3C0944D40734F2D3BACA2FF6D133C10EC },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereSelectEnumerableIterator_2_t1F5FF34DBCE1F6AF7517393D73D356A6DA50B6D1 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereSelectEnumerableIterator_2__ctor_mF3A2E2792E40371499F8A04F1C4B4CF725C70204 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1__ctor_mB182060F0BAD71C29739D1A67593C75D932D1F99 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Iterator_1_t401B0AE4A7AE625421285FB386F87D7EB1213E82 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereArrayIterator_1_t3191C8D5170E56806A48BD846333ABBD99D3D3C7 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereArrayIterator_1__ctor_m4D241BD7A7C7BF59DEFF9D7D34B8E23771934CFE },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_t9550E469110084BCEB11807FD34F94E9615475E5 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_mCC45E416C5C54731DCA65FEFD545FDC5F4D10DA7 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Iterator_1_t401B0AE4A7AE625421285FB386F87D7EB1213E82 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1_Dispose_m3973A9258B5A77E6B3F7DC3D004466E6296075A9 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerable_CombinePredicates_TisTSource_tA44A3A99F6F77148305A3C32D2C4DE1D4226338A_m457636321FF5773C76C14EA990DF6EBA3827FA1C },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereSelectArrayIterator_2_t6BD47364FC721CA8B09BDFC7BE6810CCE818F41E },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereSelectArrayIterator_2__ctor_m13925FA98D8607D9EA9B1A4792AE6A94B2849DF1 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1__ctor_m474A63CD9FAA51728C0378997DDC4C8B5FE28303 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Iterator_1_t4928FCA7FD6F8CA3BFB0698285A34D6BBDE1A112 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereListIterator_1_t39045FEC3E9F1D32C0EA2780668C61E302992807 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereListIterator_1__ctor_m172443247095E67B21AF11E2907D7B644EB793DE },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_List_1_t65D73AE3589A56A7B32F4BDFCD91269AD04DD4DF },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_List_1_GetEnumerator_m62042CED4A1CF9B02B5E17694405BBB8BEEDD38C },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerator_get_Current_m21D84BB0301B459F1ADE9ABD50089FBBB8C63F97 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Enumerator_t8E62FE91E95BFC5D28A3B09EFA69C2A33120205E },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_tC858B64F5B124B5C1F30E774832D4E614DA18793 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_m1C2F1F284152F67D5FE0FD1BD2D71BD3E2DD280F },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerator_MoveNext_m1A9C394EDBEE8ABF55FA1F44A260F79D813902E4 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Iterator_1_t4928FCA7FD6F8CA3BFB0698285A34D6BBDE1A112 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1_Dispose_m84B51BBBD674EB42CD5E238D01DC427248C5043F },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerable_CombinePredicates_TisTSource_t85B7C93A555823AE666813BFFC5FEC432E108956_mEF6DF5A93E207AEA02FF346A380F597872BF6F49 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereSelectListIterator_2_tA11FC7FED3C26063A55DAAA599906A1C57175B03 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereSelectListIterator_2__ctor_m89A10922BF0309154D097D4D7E630E8451C1B952 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1__ctor_m24F4541F8829F51E57F84D96054E563391732CFC },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Iterator_1_tA31D49CCC35E12E44AB58CA8F1ABB8B79289764F },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereSelectEnumerableIterator_2_t48BC8AE4F3D8AE2BB3FB23C3AFC140A756CC65A4 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereSelectEnumerableIterator_2__ctor_mDA7AA133551DE9DAA42B9489EF99A53B6BF80749 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1_Dispose_mEC8779D213FB3A1CF689B52F5B8219238E54A57B },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_tA64D266802CC654E58E383563C59E5BC49B1AD22 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_m8A5C078C211D763A5213D0930EBD38A3D97EA825 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_t01303709A68F833425B5740A2A2D972A0DDEEB26 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_mFE78B9CDC5BBDF50E78AFAD9CFE23F2223C79F5B },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_t86CFE648CE7192981F7DA895E30FBDA1F513B652 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_m4148D75120CEABE2FF0024661FDDBFCB6BA771A5 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_tD5EAA29CDB4313FE2590F76DD99FB1497FF215B1 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_m76A5030A28A4F68091A624D3302941DB8B4E0765 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Iterator_1_tA31D49CCC35E12E44AB58CA8F1ABB8B79289764F },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereEnumerableIterator_1_t46D8F3B462050CB986339EA63B34443BA66D5EE9 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereEnumerableIterator_1__ctor_m05CA91B0739729D9DFB15FD9AE29358281C4DF95 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerable_CombineSelectors_TisTSource_t5B0D27614F68D07DB050466831DEDC1DDEFFC093_TisTResult_t33CDF94D13BEBA6908E84F958D63A95F7466E520_TisTResult2_tACCDF53F8D9C783083BE76E1EBF4F0851CBEA20C_mF0413C490C865332533AAD91E5E31905E989A32D },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereSelectEnumerableIterator_2_t091A81B2BFDECBB6B85A5DE344E32E306B979F4E },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereSelectEnumerableIterator_2__ctor_mF714167A39020832C4835CAA8F81F6E0FAA9A789 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1__ctor_m6A1E7CB836C19C0B9439096586A06D0057E7AA52 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Iterator_1_tEE17D73E1A34A4CF384B00C3E896D8BCCA8406C7 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereSelectArrayIterator_2_t2F5234271A3A4E5F89C63030DD6F9D9260D06FDE },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereSelectArrayIterator_2__ctor_mCD9A624F8C3ACA086CFD4CEBB6150456E1471C9B },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_t47CC59E1937CA3FCC9DA471AAD5C7899D9AFF9DF },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_m8DAC2E225A682443964FAEA00BE2C728AAD74B0D },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_t8A5A56224271942180907637F3E10A9A3CBDAEDF },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_mFA2E82CEFB4B24BDB33564DECDF4765D2B7C7053 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Iterator_1_tEE17D73E1A34A4CF384B00C3E896D8BCCA8406C7 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1_Dispose_mA9BFBEB710778B3A052F66CEDA033562C82E1D71 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereEnumerableIterator_1_tC18F5A6D2AF40216AE21EBC6827AD147E31E17A5 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereEnumerableIterator_1__ctor_mA5B3E7EB5B0FFE980FA8EE42233961A20AC087F7 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerable_CombineSelectors_TisTSource_t21BF09076F270DC063711DE3ABB52B001A331F78_TisTResult_t278B55150BC17BB45D33B605F011F4D96EFE5425_TisTResult2_tEC28CE9F47F4F949C7CD44736D7F4B15360A65F9_m5CAC93D4ECC6772D64346C0581C436601A3E07B1 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereSelectArrayIterator_2_t59D43E919F2DC1D758D7C811297A1435D53D93AC },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereSelectArrayIterator_2__ctor_m1F6E197D75A7ECC536CF790E45D8855D46A1FDC6 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1__ctor_mAB5D6B06319C192633E05B6EBBA9A168FF73AAE9 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Iterator_1_t908D71005972796790D5ED7033CA7098F2134EEF },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereSelectListIterator_2_tBA41BFF0DB2BFE973868036026CDCA6B8797A8D6 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereSelectListIterator_2__ctor_mDFE79323B2924E6309386ABFB7F9AE7BAAD059C2 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_List_1_t905EFEC983EC5317F0B1F633D205BF984BB0BE1D },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_List_1_GetEnumerator_m906D8353E6DC2D62B1C6ACF3849D1970361C7AED },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerator_get_Current_mEB276D052415C98826154DC4FDF8574C48E0FAF0 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Enumerator_t8A622325AF1352D3AB0ECDBB45A0AFB7AF959716 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_tBE76289600B0D10382BAB5D9F828D996195A6D07 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_mF94AE9E660C674B47621BAB249E8B2D27BF85E73 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_tC25DAB584B0F47C1DAA1B56A2C30A3D42B88D146 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_m74CA45C07863967094098CE16E020CA52859B1D3 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerator_MoveNext_mD3BAB36AFD8333EB35A46C14C441E1B1A7493CED },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Iterator_1_t908D71005972796790D5ED7033CA7098F2134EEF },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Iterator_1_Dispose_m741197394517AA91B94A9D65A084BBAED71C3C3A },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereEnumerableIterator_1_t957AB458B1F7D316B1F8960AE854A6CD7E1DD852 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereEnumerableIterator_1__ctor_mF25AEB188FA18B82EFB71A5BAD8534E8A1FFCEE2 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerable_CombineSelectors_TisTSource_tEB7490DB2885922B8C60E28873F5DB811BD9CEB3_TisTResult_t11AC9139084FDCB528CAF75FE5166467D3329A05_TisTResult2_tECB8FBA56F78B893A9D06A35F011858B7CE2F3E3_m0C731C937555DEE92384A692B1DBACCBB7BE7740 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_WhereSelectListIterator_2_t8C5A1568CD9B2B2E7760D591DD3A4517DB930770 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_WhereSelectListIterator_2__ctor_m43F52D624D5D5CFF28C6B99849AC99EBE6E71A4F },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_t756BE45FD1B4569EBD49EAD2AB1444B766D13F83 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_mE7A8E49A025849A2FE64A86343365C1808AD743F },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_tE17298D4C6D18DE4FB73F421AF563BE9FB9630EB },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_m176EFBF601E4DFA96422134D1F9C9A90B94D6ACF },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_tB89E2A0A82E89B19927B092B238720F65A87EBE4 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_mE58690AB3F029696906A136F1FFDCB60D54D4C85 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CSelectManyIteratorU3Ed__17_2_U3CU3Em__Finally2_mF728E3C6B29EA0DF10D3BA06045AD22644EA3E9B },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CSelectManyIteratorU3Ed__17_2_U3CU3Em__Finally1_m3F705537F51F06056319F653E2259BB61FDFC84F },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_tD1389C38D56436639122F61396C8E429889C377A },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_m8C99896D8A616F86338CC80E782077A0E16AF4F1 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_tFD0011EBB450CC3BF27CEC691ECB0C3AECC7749F },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m6140A669FD20F62976EC9AD7ABC81919CD1D766F },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_t613FB799F1283E17E4BF8D5FE514CD5881BA76C1 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_m8DF7C3A537A90832C0824CE33EF2FEBE066C6A41 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_tC9F000960A1A3A72A5A8918F1119FCF380D4E487 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_m04A4AE5BFD2F48213FF247D36BBE7E18877F921F },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_tE098A91CD077E31FC61135B5029A16072F2C0FAC },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_mA70C959D540989A08393DCCB40FC89064E6EE422 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CSelectManyIteratorU3Ed__17_2_System_IDisposable_Dispose_m4F9011CE53A860AD076D2E84B4D9A628DFE8EF34 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_TResult_t35BDCF3171C0EE725B7DC1042A0653542D1C8B80 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_U3CSelectManyIteratorU3Ed__17_2_t80F0A8E8CD72F862C9756B513CA0E69CA552C0D1 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CSelectManyIteratorU3Ed__17_2__ctor_mA4E3202CDBBD9520C0E219EEBA20CBE5B69ECDA8 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CSelectManyIteratorU3Ed__17_2_System_Collections_Generic_IEnumerableU3CTResultU3E_GetEnumerator_m08198DA1542C22E9478C94AE9559F13D8591B212 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CTakeIteratorU3Ed__25_1_U3CU3Em__Finally1_m494D6DFFD2769A08E71FCB5268585CE8C4368710 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_t741381B26B9B030123F10D94CE5EF70D38CD14DE },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_mAAD097C73F4FE79A08A24E41609D722C02853962 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_t6E27CA42389E86E380DD3026EE211BD2D000CCD9 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m62EDABBDED39F332722B912AB74324C8AA619064 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CTakeIteratorU3Ed__25_1_System_IDisposable_Dispose_m1315DA05FF75DEB001ACA5957881E651530C754B },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_TSource_t02EF8D3CCA7118FDF603FB8654AF79F2FF0F068A },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_U3CTakeIteratorU3Ed__25_1_t603726036225D0D95B94BB017D6AABC6E951DE78 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CTakeIteratorU3Ed__25_1__ctor_m79C3BF1547D94C46115616E921DE026268EED0A3 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CTakeIteratorU3Ed__25_1_System_Collections_Generic_IEnumerableU3CTSourceU3E_GetEnumerator_mE26E1BD6C775B6F1CC0C3CF9A95A0D18EA92C4DF },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CDistinctIteratorU3Ed__68_1_U3CU3Em__Finally1_m5A1FD8F557D9372B7207DA439D3F5400A5D680AB },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Set_1_tF01934D2229565F204C9ADF13158DCCB8CCD2EB7 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Set_1__ctor_m815CB40BA85CEF706F531B7BF439E4D505BB5E42 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_t43811822819B75BE6619279ABA5B08ADD11A36C6 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_mAFA75F0FA4A7759C4ECC79C7F42CE043C0BBE463 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_t2A2E2EF21339FD112C964B9CF2654AA9BAE4F2CA },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_mEE747CACD72C9E1BBB4DB60B37811664ED7DC536 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Set_1_Add_m7DC65238C38BBB6ADCC867FD478D64A4338BA366 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CDistinctIteratorU3Ed__68_1_System_IDisposable_Dispose_mE5F9EBDAF6CE2E21979B6940EA37E5544C7DFF27 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_TSource_t3FF79E3F222559BCCBA35ED008F0F85B66E62A00 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_U3CDistinctIteratorU3Ed__68_1_t9F1140F3B4BD52639A46DEAC9764A78092C97305 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CDistinctIteratorU3Ed__68_1__ctor_m412D5949A71FB2DF622581177F22A884DDC67287 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CDistinctIteratorU3Ed__68_1_System_Collections_Generic_IEnumerableU3CTSourceU3E_GetEnumerator_mBE8DC2773FB7231E662A140F2047ECA0B63D6879 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CExceptIteratorU3Ed__77_1_U3CU3Em__Finally1_mACA5CC35C36BCCC30B81B26C8E0B555C3DFF906A },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Set_1_tC97E83E279EA20D849DD344BAD2B918EEE71896A },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Set_1__ctor_m992E04FD43623CA91D67886AD1EA9C6FE2DDD100 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_t3C9331E70299CEDFA221B9358DCA46615CDAD471 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_m7AC9B87A0C94E96D3D2A56B4D9686E9671048A95 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_t510E4AD6C23F76BD0971C744CE12085C1A2057F3 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m8806160817B932495F753E1C2D1138991CD16BCA },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Set_1_Add_m59B7D39F64711E39511E5F279ED1F1C77570DADF },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CExceptIteratorU3Ed__77_1_System_IDisposable_Dispose_m4357E56ADF355A7446F0CFE200BF33171BA67EE2 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_TSource_tE967D1BA8CA00781B8F695FA112AD70C48CB6878 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_U3CExceptIteratorU3Ed__77_1_t7A68C5D64D78B1068E46396C69CEDFB837178E9E },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CExceptIteratorU3Ed__77_1__ctor_m5162331A0E564DCF9EDBBF01855F67BDA43F3CC2 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CExceptIteratorU3Ed__77_1_System_Collections_Generic_IEnumerableU3CTSourceU3E_GetEnumerator_mE1D729057481B4E547167276A83BAF8B9BB810C8 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_TElementU5BU5D_t5FE845F5AF158D61A1612AC86BF41A482409E218 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_EmptyEnumerable_1_t903C1B1D5A3723EB325CD99884D858F929D989D3 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_EqualityComparer_1_get_Default_mF9ADBF37046B00B4C61CA959D6EC4A851302041A },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_EqualityComparer_1_t3C6F85286B5844659CD99C8CD82F39A1027D0E28 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_SlotU5BU5D_t505B87EE9501DF282930D90EBCE91A5A51A6ADB6 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Set_1_Find_m0EE1659DEEEBAB3ECCC1F697BADD51B15F897CB4 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Set_1_InternalGetHashCode_mEB2BF942411714E6D3DF54C3B8C84C81FECF480F },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEqualityComparer_1_t253FDF060C665D2CAE293B27514148BC04F881E2 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEqualityComparer_1_Equals_mE91439EC229D29977A94DDFDE430E5512204C1ED },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Set_1_Resize_mC350A354D2354B256A23057B23D4977E4653170F },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_TElement_t65838287198D29C1A2F194E4FBD25389CA14586D },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEqualityComparer_1_GetHashCode_m72FC6D66920C3DFDB7422DCC3D13CE50ED7E24A8 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_U3CGetEnumeratorU3Ed__1_t3CC996D75E05583A2C68BDAA6119DD5395C4CAEE },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_U3CGetEnumeratorU3Ed__1__ctor_mD3A17D2F3E5D0A469641D57A4AB655B4545F375E },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_OrderedEnumerable_1_GetEnumerator_mBBDBE3B4727EE491AF45177AF6A25516F22737D7 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_OrderedEnumerable_2_tBEC552CAD99DF0748B3CF3552F93BE83E3A03F3F },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_OrderedEnumerable_2__ctor_m8890686A74F81E8473FB5D036EE0D750597D2994 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Buffer_1_t41F8077A5F13608D5270B50E18148B45F5F315C7 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Buffer_1__ctor_mA99E4505CFF1FED56FB8272A49E274F14DBB6727 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_OrderedEnumerable_1_t9A3D8D2850455B28D36B701298D0B1331F534031 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_OrderedEnumerable_1_GetEnumerableSorter_m5F587D4742CDA03CB231EF0741B98D9EB7EF4E84 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_EnumerableSorter_1_tA62734D066C60347DFE7A135B5958DFFCF9E8C51 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_EnumerableSorter_1_Sort_m82301704DAE9F05F1C2681B4E735E04BB7919073 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_TElement_t7131B4894D970BCE712C2414419F0A27829AF29C },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_OrderedEnumerable_1__ctor_m920D35170CC92329CACC9CFB60EF8BB9C06FF9FF },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_OrderedEnumerable_1_t06CB3897759B3B58FCFDD71EC11AFB8E99366F94 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Comparer_1_get_Default_m9436BB4B67683FA68956FF78111C7DA24A35FD25 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Comparer_1_t05930316C99AB50EC343359F3B8840EEADD7452B },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_EnumerableSorter_2_t8479B5254E2828D3550EA1B532B05EDB1B1215D6 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_EnumerableSorter_2__ctor_m18A2FE6C6F5054713B98012F0E2CD0B5DB7C20BE },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_OrderedEnumerable_1_t06CB3897759B3B58FCFDD71EC11AFB8E99366F94 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_OrderedEnumerable_1_GetEnumerableSorter_m7268D01B139AF537E1343B1EC035A4E3EB18243D },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_EnumerableSorter_1_tBB9ADD7C21E31739D9683D99CFF9DC117D8BAB11 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_EnumerableSorter_1_ComputeKeys_m0261683B46812CA7A0CEB845C1EF325F8033694E },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_EnumerableSorter_1_QuickSort_m01455655602074FD67BC431F21F62F7A9180571C },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_EnumerableSorter_1_CompareKeys_mFB513F8D369E5221DD6F66ACC4F34A50807CDBC6 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_EnumerableSorter_1__ctor_mFF96BE3E2A79A8BC38E1A650D9434EA57297BF46 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_EnumerableSorter_1_t053F2BD859874727D1E461B965976B49B4A173C7 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_TKeyU5BU5D_tE5676E72B1BCCA85AD5A6118A3858A2144C86857 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Func_2_t5E10C25103ED51C0C843F4F679CFF099A92D2033 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Func_2_Invoke_m8D38D643551E8034BC2F061748DC2E8A54B8FC99 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_EnumerableSorter_1_t053F2BD859874727D1E461B965976B49B4A173C7 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_EnumerableSorter_1_ComputeKeys_mFBB6EE61ABB9424BD1DD39936A10EA3D454AF202 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IComparer_1_t1FA8428328A44FE33A3569A2A717B4CC10F6D553 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IComparer_1_Compare_m392095FFDA3D97DA5903FA4F1CCEE94E1CA1E5BA },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_EnumerableSorter_1_CompareKeys_mA39249DC095B5EC415BF70815665F8483E6229D6 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_ICollection_1_tB92B34A134CB1BF586A69F2A283CF79675A37E1D },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_ICollection_1_get_Count_m853E49D009E94914082E87AD16E91AD4A7694DEE },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_TElementU5BU5D_t65424EAA6380C3A80C7FCEBE88D5E248445EFD15 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_ICollection_1_CopyTo_m1623FBCB4E13BACF6CA953F8F38FD10B4ABDC6C9 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_t03135CC19B082BC866CC79592745590E608D5CE4 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_mD5E0E805DDE55F5756E21D0D5FEDB2220FA39060 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_t13EFC35CCC3C9F302141EE5C116481E1CF2CDC48 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m1BB68E9CA48B668E739FD9AF759EEE794E0CC7A5 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Dictionary_2_t6D06D4E5F7D25D56B6A19114BD410EF7C1C8EEA2 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Dictionary_2__ctor_mA3368FADA46D2FDD7428CC536AFDE4C19B13566E },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Dictionary_2_Add_mCF74069775EA16349F780044744CAC6EC238E676 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Dictionary_2_TryGetValue_m67E55BB9DBE7FAE34B406D048D0703B26806DE65 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Dictionary_2_get_Count_m6B4D3CEE28B6F7E6220C9A0E41A7733593A7E9F2 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_tD1F5957398D4DB123961818284415FBE534BC22A },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_m79AC5FCCE7F0D4D2BACD98F05A3F9F0CD85BE410 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_t71282494681DD34DFA6390FBAD52FED29986855E },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m05021FC24229AA1EDAA31B2C322380C83965C5AE },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IReadOnlyCollection_1_t643AA0DE2BD19AF4360D7AAAD04DE5D6F8472ED4 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IReadOnlyCollection_1_get_Count_m50B71DE8246F5B1338CD8E5BE3EF8102FFEBA343 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Action_1_t18FBEFC0DF729459650EE8BC850E8423F348794F },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Action_1_Invoke_mDF3038D2095CCE9649DAADE5466CD69E954FCD89 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_CacheDict_2_AlignSize_m44DAB39A428C07B7887289D3B26CC228C4F90E72 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_CacheDict_2_t656AB3D5CCFCBC43AE10036192190A1EE1EE9A5E },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_EntryU5BU5D_t0A8C6A83EA4B5CE761F205824E8C6FF9FB255ADD },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_TKey_tB5D0C0709F7D188CFFC5CCAA6B565FC07556B3FE },
	{ (Il2CppRGCTXDataType)5, (const void *)&g_rgctx_TKey_tB5D0C0709F7D188CFFC5CCAA6B565FC07556B3FE_Object_GetHashCode_m372C5A7AB16CAC13307C11C4256D706CE57E090C },
	{ (Il2CppRGCTXDataType)5, (const void *)&g_rgctx_TKey_tB5D0C0709F7D188CFFC5CCAA6B565FC07556B3FE_Object_Equals_m07105C4585D3FE204F2A80D58523D001DC43F63B },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Entry_tB6EBBB0269749705EFC7FCB0B768B4F45CB7FC63 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Entry__ctor_m9750D60F6EB3DC46DB0642B51C0150979A873A22 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_CacheDict_2_Add_mCC2EF29D9ADDB74392FFBD05E20BE780327E0938 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_EqualityComparer_1_get_Default_mC93F859DDE3938407D49FF1E5A96CED45C316265 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_EqualityComparer_1_tA96567156D027DA41596C9CA1C5DEAB0CDEE6C60 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1__ctor_m781AB04365DCD9333E443C412DFFE8102DCAA2D0 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1__ctor_m07CC1E138E0D451EA7ED1AC941AC1245011C2093 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_HashSet_1_tF089CA52CB584DB29B4FF68C4A59B7C5FBD3630A },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_AreEqualityComparersEqual_m0E95D8BA36E2A85337C69FE839358C53D874D82C },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_HashSet_1_tF089CA52CB584DB29B4FF68C4A59B7C5FBD3630A },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_CopyFrom_mF3114EC5E22390EB6044B5BB4731BE3733A2AACA },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_ICollection_1_t0962A9980803A8F46108387826B91CD4DB9B0F97 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_ICollection_1_get_Count_mC4059B0C3219EDC8E97DE3ECFF2B0A4A0280801E },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_Initialize_m06C4A2DE0A243BB8A2D0C4345712ED9B91231993 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_UnionWith_m630B15B252A9518ACDC7F2CC33E343AF51C014B1 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_TrimExcess_m772030970D2E00DEA17364C4A8633644B366DE11 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_SlotU5BU5D_tCF3C9EE13C54F730A642AD5F260A5A7D2F9F73F7 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_AddValue_m1539D2475B8B90B247ED5A3C4E01698DF6D74F19 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_AddIfNotPresent_mF89D8C4E328F141B43BA304A67EFAE78CF643968 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_InternalGetHashCode_m175DF882B346A324B102A8692CA09758B465DF72 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEqualityComparer_1_t66DFFD1D981BA05FF20035307F86BFC3864B2E2B },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEqualityComparer_1_Equals_m0539178A3A28082426D3792F170D842E3F99CCA6 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_CopyTo_mAC8E7BAAD9DE7ECC11D9FC60E3A4FBD661B4A329 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Enumerator_t45B9839DDB003D337DAD360EE2D7537B7E8F9F2D },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerator__ctor_m757B4624317C66B0082A97D86F44F4732370B396 },
	{ (Il2CppRGCTXDataType)1, (const void *)&g_rgctx_IComparer_1_t6BC8594DB26FCC0B360DE8C22BD01836BA24C8AC },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_TU5BU5D_t6BCCEA57BEA1E43097B80E2965A5789452F93BA0 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_CopyTo_m636F301EC0DFB1B2F58553B0EE2E5D4B41B02261 },
	{ (Il2CppRGCTXDataType)1, (const void *)&g_rgctx_TU5BU5D_t6BCCEA57BEA1E43097B80E2965A5789452F93BA0 },
	{ (Il2CppRGCTXDataType)1, (const void *)&g_rgctx_IEqualityComparer_1_t66DFFD1D981BA05FF20035307F86BFC3864B2E2B },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_SlotU5BU5D_tCF3C9EE13C54F730A642AD5F260A5A7D2F9F73F7 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_TU5BU5D_t6BCCEA57BEA1E43097B80E2965A5789452F93BA0 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerable_1_t08DFCA249A6163529549D46ACA84A83C8CD361EC },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerable_1_GetEnumerator_mD059A216A04E59863006CEE9F7C3BD8AA41F1D5C },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_IEnumerator_1_t1BD2EC88A1B4550751DED0BBB53571254F37887A },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEnumerator_1_get_Current_m149653A74BD91288C695A04557C5D768E16EA745 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_Clear_mBCB831BE78A9259AAEFB3051763BAE40121F9D11 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_IntersectWithHashSetWithSameEC_m44EC438AB13789AE47C1FE321760937D6B93586F },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_IntersectWithEnumerable_m7A0EB45FE7BD56851D687DBFA37C331E4CE25E77 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_Remove_mFD3EA80DFC96201A988DBFBD52A4F920AFB5384D },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_SymmetricExceptWithUniqueHashSet_mD194BE9E68BDFEEAC21CC0AEF0A29B09B0AE16B7 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_SymmetricExceptWithEnumerable_m8B945926110C56656B148F3F7A52ED0DB7894DE3 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_get_Count_mF76AC662D895CC68C20E848F79874EAB1A79DA31 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_IsSubsetOfHashSetWithSameEC_m9E35091BBA5F31F05AAD8A0E2C2EBA07AC600E6A },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_CheckUniqueAndUnfoundElements_mEA361D87EEB7BAD67D2F3CE429595DEFA932A5DE },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_ContainsAllElements_mCF6E110D72174582EF10330832B7D5A28D3183F0 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_Contains_m9FC46B9B95724A3C501B1AB2A623A4DDEE540ED3 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Predicate_1_t1F12E2E3D79CAB6F034E6063432D655A79E0C690 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Predicate_1_Invoke_m1E90162EC37F65593DEE945DFC92BA7B4259B3B7 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_SetCapacity_mBAE6B90A5CE1BD75B08B8527763700172A4ADB69 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_IncreaseCapacity_mC430EB8352A6B45A9776BF3373EEE6551FC85ABE },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_GetEnumerator_m477CCED045EA6DDD1DD1A3EB43BC20397E889D37 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerator_get_Current_mDAB434264D5F378E41D5E46055A8797685BD2A3B },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Enumerator_t45B9839DDB003D337DAD360EE2D7537B7E8F9F2D },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerator_MoveNext_m8945184F458AB61968C5BCB26E20FAD91B6114D1 },
	{ (Il2CppRGCTXDataType)5, (const void *)&g_rgctx_Enumerator_t45B9839DDB003D337DAD360EE2D7537B7E8F9F2D_IDisposable_Dispose_m3C902735BE731EE30AC1185E7AEF6ACE7A9D9CC7 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_InternalIndexOf_m2D447E428750224983163A2C527019856AFDBFBC },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_AddOrGetLocation_mAE6A7B28983C117BB3D9C8C21448236DF99B922A },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_HashSet_1_get_Comparer_m313EEB5FFD720AD1F35ABB61097076D8ABE48A73 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_T_t1A61667A2FF6D68BB3DAC186281F928B7ED2DB94 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_IEqualityComparer_1_GetHashCode_mB43AB2E622EB30D675693CDC96CA5D836DE43336 },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_Enumerator_get_Current_m6F22509C5AEA1EA15942F7F9C9866256CB3EA347 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_Enumerator_tB091A59F0E047A76EF2099D441944326FE3C0B97 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_T_t6D22409F37413B725563BF484486F55FB7202BB8 },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_ICollection_1_tFEFB414626FD111D128FEBCF2B2893D2D1BFA23B },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_ICollection_1_get_Count_m59A49BC41F6F347F1A5161D5C655CC8F14B4465C },
	{ (Il2CppRGCTXDataType)2, (const void *)&g_rgctx_TU5BU5D_t7141ABD7B24C6F56B55DB7911E6CE85CAACA4FFF },
	{ (Il2CppRGCTXDataType)3, (const void *)&g_rgctx_ICollection_1_CopyTo_m142EAE547CEB167F8913259B3A9EBEF7718F80AD },
};
IL2CPP_EXTERN_C const Il2CppCodeGenModule g_System_Core_CodeGenModule;
const Il2CppCodeGenModule g_System_Core_CodeGenModule = 
{
	"System.Core.dll",
	338,
	s_methodPointers,
	0,
	NULL,
	s_InvokerIndices,
	0,
	NULL,
	66,
	s_rgctxIndices,
	443,
	s_rgctxValues,
	NULL,
	NULL, // module initializer,
	NULL,
	NULL,
	NULL,
};
