
#include"Set.h"

void set_init(Set *set, int(*match)(const void *key1, const void *key2), void(*destory)(void *data))
{
	list_init(set, destory);
	set->match = match;
	return;
}

int set_insert(Set *set, const void *data)
{
	//do not allow the insertion of duplications.
	if (set_is_member(set, data))
		return 1;

	list_ins_next(set, list_tail(set), data);
}

int set_remove(Set *set, void **data)
{
	ListElmt *prev = NULL,*member=NULL;
	for (member = list_head(set); member != NULL; member = list_next(member))
	{
		if (set->match(*data, list_data(member)))
			break;

		prev = member;
	}
	if (member == NULL)
		return -1;

	return list_rem_next(set, prev, data);
}

int set_union(Set *set, const Set *set1, const Set *set2)
{
	set_init(set, set1->match, NULL);
	for (ListElmt *member = list_head(set1); member != NULL; member = list_next(member))
	{
		if (list_ins_next(set, list_tail(set), list_data(member)) != 0)
		{
			set_destory(set);
			return -1;
		}
	}
	for (ListElmt *member = list_head(set2); member != NULL; member = list_next(member))
	{
		if (set_is_member(set, list_data(member)))
			continue;
		if (list_ins_next(set, member, list_data(member)) != 0)
		{
			set_destory(set);
			return -1;
		}
	}
	return 0;
}

int set_intersection(Set *seti, const Set *set1, const Set *set2)
{
	set_init(seti, set1->match, NULL);

	for (ListElmt *member = list_head(set1); member != NULL; member = list_next(member))
	{
		if (set_is_member(set2, list_data(member)))
		{
			if (list_ins_next(seti, member, list_data(member)) != 0)
			{
				set_destory(seti);
				return -1;
			}
		}
	}
	return 0;
}

//insert members in the set1 not in the set2
int set_difference(Set *setd, const Set *set1, const Set *set2)
{
	for (member = list_head(set1); member != NULL; member = list_next(member)) {
		if (!set_is_member(set2, list_data(member))) {
			data = list_data(member);
			if (list_ins_next(setd, list_tail(setd), data) != 0) {
				set_destroy(setd);
				return -1;
			}
		}
	}
	return 0;
}

int set_is_member(const Set *set, const void *data)
{
	for (ListElmt *member = list_head(set); member != NULL; member = list_next(member))
	{
		if (set->match(data,list_data(member)))
			return 1;
	}
	return 0;
}


//Determine if set1 is a subset of set2.
int set_is_subset(const Set *set1, const Set *set2)
{
	if (set_size(set1) > set_size(set2))
		return 0;
	for (ListElmt *member = list_head(set2); member != NULL; member = list_next(member))
	{
		if (!set_is_member(set1, list_data(member)))
			return 0;
	}
	return 1;
}

int set_is_equal(const Set *set1, const Set *set2)
{
	 if (set_size(set1) != set_size(set2))
		return 0;

	 return set_is_subset(set1, set2);
}