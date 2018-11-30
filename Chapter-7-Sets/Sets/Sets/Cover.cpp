#include"Cover.h"

int cover(Set *members, Set *subsets, Set *covering)
{
	ListElmt *member = NULL,*max_member=NULL;
	int maxsize = 0;
	KSet *subset;

	Set *maxset;
	Set *intersection;

	while (set_size(members) > 0 && set_size(subsets) >0)
	{
		//determine a subset that includes the most elements
		for (member = list_head(subsets); member != NULL; member = list_next(member))
		{
			maxsize = 0;
			if (set_intersection(intersection, members, &((KSet *)list_data(member))->set) != 0)
			{
				return -1;
			}
			if (set_size(intersection) > maxsize)
			{
				maxsize = set_size(intersection);
				//maxset = &((KSet *)member)->set;
				max_member = member;
			}

			set_destory(&intersection);
		}
		/**************************************************************************
		* *
		* A covering is not possible if there was no intersection. *
		* *
		**************************************************************************/
		if (maxsize == 0)
			return 1;

		subset = (KSet *)list_data(max_member);

		//insert the maxset
		if (set_insert(covering, subset) != 0)  //at first i only insert the A1 A2 , but there is going to insert KSet which include A1 A2 as well as their sets such as a,b,c,d
			return -1;

		maxset = &subset->set;
		for (member = list_head(maxset); member != NULL; member = list_next(member))
		{
			set_remove(members, &list_data(member));
		}
		//delete the elements that in the maxset and delete the maxset in the subsets
		set_remove(subsets, (void **)&maxset);
	}
	return 0;
}