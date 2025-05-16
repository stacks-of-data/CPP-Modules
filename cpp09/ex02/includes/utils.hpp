/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:51:37 by amsaleh           #+#    #+#             */
/*   Updated: 2025/05/16 22:02:57 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

typedef struct	SBlock
{
	int				val;
	struct SBlock*	prevA;
	struct SBlock*	prevB;
}	TBlock;

size_t	batchSequence(size_t k);

template <class T>
void	displaySortedSequence(T& before, T& after)
{
	std::cout << "Before: ";
	for (size_t i = 0; i < before.size() - 1; i++)
		std::cout << before[i] << " ";
	std::cout << before[before.size() - 1] << '\n';
	std::cout << "After:  ";
	for (size_t i = 0; i < after.size() - 1; i++)
		std::cout << after[i] << " ";
	std::cout << after[after.size() - 1] << std::endl;
}

template <class T>
size_t    binarySearchBlockIndex(T& contA, int val)
{
    size_t low = 0;
    size_t high = contA.size();
    size_t mid;

    while (low < high)
    {
        mid = (low + high) / 2;
        if (val == contA[mid].val)
            return (mid + 1);
        if (val > contA[mid].val)
            low = mid + 1;
        else
		{
			if (mid == 0)
				break;
            high = mid - 1;
		}
    }
	if (low < contA.size() && val > contA[low].val)
		return (low + 1);
    return (low);
}

template <class T>
void	packBlocks(T& contAOld, T& contBOld, T& contA, T& contB)
{
	TBlock	tmpBlock;

	for (size_t i = 0; i < contAOld.size() - 1; i += 2)
	{
		if (contAOld[i].val < contAOld[i + 1].val)
		{
			setBlockData(tmpBlock, contAOld[i + 1].val, &contAOld[i + 1], &contBOld[i + 1]);
			contA.push_back(tmpBlock);;
			setBlockData(tmpBlock, contAOld[i].val, &contAOld[i], &contBOld[i]);
			contB.push_back(tmpBlock);
		}
		else
		{
			setBlockData(tmpBlock, contAOld[i].val, &contAOld[i], &contBOld[i]);
			contA.push_back(tmpBlock);
			setBlockData(tmpBlock, contAOld[i + 1].val, &contAOld[i + 1], &contBOld[i + 1]);
			contB.push_back(tmpBlock);
		}
	}
	if (contAOld.size() % 2)
	{
		setBlockData(tmpBlock, contAOld[contAOld.size() - 1].val, &contAOld[contAOld.size() - 1], &contBOld[contAOld.size() - 1]);
		contB.push_back(tmpBlock);
	}
}

template <class T>
void	unpackBlocks(T& packedContA, T& contA, T& contB)
{
	T	unpackedContA, unpackedContB;

	for (size_t i = 0; i < packedContA.size(); i++)
	{
		unpackedContA.push_back(*(packedContA[i].prevA));
		unpackedContB.push_back(*(packedContA[i].prevB));
	}
	contA = unpackedContA;
	if (contA.size() != contB.size())
	{
		TBlock tmp = contB.back();
		contB = unpackedContB;
		contB.push_back(tmp);
	}
	else
		contB = unpackedContB;
}

template <class T>
void	recursiveFJ(T& contA, T& contB)
{
	T	res, newContA, newContB;
	if (contA.size() > 2)
	{
		packBlocks(contA, contB, newContA, newContB);
		recursiveFJ(newContA, newContB);
		unpackBlocks(newContA, contA, contB);
	}
	contA.insert(contA.begin(), contB[0]);
	size_t k = 2;
	size_t currBatch = batchSequence(k);
	size_t prevBatch = batchSequence(k - 1);
	while (currBatch < contB.size())
	{
		size_t i = currBatch;
		while (i > prevBatch)
		{
			size_t j = binarySearchBlockIndex(contA, contB[i].val);
			contA.insert(contA.begin() + j, contB[i]);
			i--;
		}
		prevBatch = currBatch;
		k++;
		currBatch = batchSequence(k);
	}
	if (prevBatch < contB.size() - 1)
	{
		currBatch = contB.size() - 1;
		size_t i = currBatch;
		while (i > prevBatch)
		{
			size_t j = binarySearchBlockIndex(contA, contB[i].val);
			contA.insert(contA.begin() + j, contB[i]);
			i--;
		}
	}
	contB.clear();
}
