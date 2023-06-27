#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - Comparngs.
 * @s1: The firso be compared.
 * @s2: The second  compared.
 * Return: Positive byte
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_value - Get the f a card.
 * @card: A pointer to aard.
 * Return: The nuf the card.
 */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deck_kind - Sort  diamonds.
 * @deck: A pointer to ed list.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *itere, *inserte, *tmpe;

	for (itere = (*deck)->next; itere != NULL; itere = tmpe)
	{
		tmpe = itere->next;
		inserte = itere->prev;
		while (inserte != NULL && inserte->card->kind > itere->card->kind)
		{
			inserte->next = itere->next;
			if (itere->next != NULL)
				itere->next->prev = inserte;
			itere->prev = inserte->prev;
			itere->next = inserte;
			if (inserte->prev != NULL)
				inserte->prev->next = itere;
			else
				*deck = itere;
			inserte->prev = itere;
			inserte = itere->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - Sort a
 * @deck: A pointenked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *itere, *inserte, *tmpe;

	for (itere = (*deck)->next; itere != NULL; itere = tmpe)
	{
		tmpe = itere->next;
		inserte = itere->prev;
		while (inserte != NULL &&
		       inserte->card->kind == itere->card->kind &&
		       get_value(inserte) > get_value(itere))
		{
			inserte->next = itere->next;
			if (itere->next != NULL)
				itere->next->prev = inserte;
			itere->prev = inserte->prev;
			itere->next = inserte;
			if (inserte->prev != NULL)
				inserte->prev->next = itere;
			else
				*deck = itere;
			inserte->prev = itere;
			inserte = itere->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck
 * @deck: A pointer tod list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
