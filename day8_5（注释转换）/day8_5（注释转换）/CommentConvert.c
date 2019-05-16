#include"CommentConvert.h"

void DoNulState(FILE*pfRead, FILE*pfWrite, State*ps)
{
	int first = fgetc(pfRead);
	switch (first)
	{
	case'/':
	{
			   int second = fgetc(pfRead);
			   switch (second)
			   {
			   case'/':
				   *ps = Cpp_STATE;
				   fputc(first, pfWrite);
				   fputc(second, pfWrite);
				   break;
			   case'*':
				   *ps = C_STATE;
				   fputc(first, pfWrite);
				   fputc(second, pfWrite);
				   break;
			   default:
				   fputc(first, pfWrite);
				   fputc(second, pfWrite);
				   break;
			   }
	}
		break;
	case'EOF':
		*ps = END_STATE;
		break;
	default:
		fputc(first, pfWrite);
		break;
	}
}


void DoCState(FILE*pfRead, FILE*pfWrite, State*ps)
{
	int first = fgetc(pfRead);
	switch (first)
	{
	case'*':
	{
	      int second = fgetc(pfRead);
		  switch (second)
		 {
		  case'/':
			  *ps = NUL_STATE;
			  fputc('\n', pfWrite);
			  break;
		  case'*':
			  ungetc(second, pfRead);
			  break;
		  default:
			  fputc(first, pfWrite);
			  fputc(second, pfWrite);
			  break;
			   }
	}
		break;
	case'\n':
		fputc(first, pfWrite);
		fputc('/', pfWrite);
		fputc('/', pfWrite);
		break;
	default:
		fputc(first, pfWrite);
		break;
	}
}


void DoCppState(FILE*pfRead, FILE*pfWrite, State*ps)
{
	int first = fgetc(pfRead);
	switch (first)
	{
	case'\n':
	{
	*ps = NUL_STATE;
	fputc(first, pfWrite); 
	}
		break;
	case'EOF':
	{
				 *ps = END_STATE;
	}
		break;
	default:
		fputc(first, pfWrite);
		break;
	}
}


void CommentConvert(FILE*pfRead, FILE*pfWrite)
{
	State state = NUL_STATE;
	while (state!=END_STATE)
	{
		switch (state)
		{
		case NUL_STATE:
			DoNulState(pfRead,pfWrite,&state);
			break;
		case C_STATE:
			DoCState(pfRead, pfWrite, &state);
			break;
		case Cpp_STATE:
			DoCppState(pfRead, pfWrite, &state);
			break;
		}		
	}
}
