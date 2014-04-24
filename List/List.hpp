//Constructeur
template <class TYPE>
List<TYPE>::List()
    {
    first = NULL;
    last = NULL;
    }

//Destructeur
template <class TYPE>
List<TYPE>::~List()
    {
    //this->Clear();
    }

//Insert à la fin de liste (supporte l'ajout dans une liste vide)
template <class TYPE>
void List<TYPE>::PushBack(TYPE* _element)
    {
    if (first == NULL)
        {
        last = new Cell<TYPE>(_element,NULL,NULL);
        first = last;
        }
    else
        {
        last = new Cell<TYPE>(_element,last,NULL);
        last->Previous->Next = last;
        }
    }

template <class TYPE>
void List<TYPE>::Insert(TYPE* _Element, Iterator<TYPE>& _Iter)
    {
    //Insert avant la position courante (limite: impossible d'ajouter à la fin!)
    //Ne supporte pas l'ajout dans une liste vide.
    //2 cas 1)Insertion au début
    //      2)Insertion entre premier et dernier
    if (_Iter.GetCurrent()->Previous == NULL)
        {
        first = new Cell<TYPE>(_Element,NULL,first);
        first->Next->Previous = first;
        }
    else
        {
        Cell<TYPE>* cell = new Cell<TYPE>(_Element,_Iter.GetCurrent()->Previous,_Iter.GetCurrent());
        cell->Previous->Next = cell;
        cell->Next->Previous = cell;
        }
    }

template <class TYPE>
void List<TYPE>::Erase(Iterator<TYPE>& _Iter)
    {
    //4 cas possibles... A vous de les trouver!
    }

template <class TYPE>
TYPE* List<TYPE>::GetElement(const Iterator<TYPE>& _Iter) const
    {
    return _Iter.GetCurrentElement();
    }

template <class TYPE>
int List<TYPE>::GetNbElements() const
    {
    Iterator<TYPE> iter;
    iter.SetCurrent(first);
    int nbEle = 0;
    while (iter.GetCurrent() != NULL)
        {
        nbEle ++;
        iter.Next();
        }
    return nbEle;
    }

template <class TYPE>
bool List<TYPE>::IsEmpty() const
    {
    return (first == NULL);
    }

template <class TYPE>
void List<TYPE>::Clear()
    {
    }

//Méthodes déjà implémentées
template <class TYPE>
Cell<TYPE>* List<TYPE>::Begin() const
    {
    return this->first;
    }

template <class TYPE>
Cell<TYPE>* List<TYPE>::End() const
    {
    return this->last;
    }

template <class TYPE>
ostream& operator<<(ostream& _sortie, const List<TYPE>& _list)
    {
    Cell<TYPE>* cellule=_list.first;

    while(cellule != NULL){
        _sortie<<*cellule->Element<<endl;
        cellule = cellule->Next;
        }
    _sortie<<endl;
    return _sortie;
    }