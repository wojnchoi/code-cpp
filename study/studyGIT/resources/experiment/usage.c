#include<stdio.h>
#include<stdlib.h>
const char *program_name;
const char *program_path;
const char *cvs_cmd_name;

# define ISDIRSEP(c) ((c) == '/')
void
usage (cpp)
    register const char *const *cpp;
{
    fprintf (stderr, *cpp++, program_name, cvs_cmd_name);
    for (; *cpp; cpp++)
    (void)fprintf (stderr, *cpp);
    exit(1);
}

const char *
last_component (const char *path)
{
    const char *scan;
    const char *last = 0;

    for (scan = path; *scan; scan++)
        if (ISDIRSEP (*scan))
	    last = scan;

    if (last && (last != path))
        return last + 1;
    else
        return path;
}
static const char *const cmd_usage[] =
{
    "CVS commands are:\n",
    "        add          Add a new file/directory to the repository\n",
    "        admin        Administration front end for rcs\n",
    "        annotate     Show last revision where each line was modified\n",
    "        checkout     Checkout sources for editing\n",
    "        commit       Check files into the repository\n",
    "        diff         Show differences between revisions\n",
    "        edit         Get ready to edit a watched file\n",
    "        editors      See who is editing a watched file\n",
    "        export       Export sources from CVS, similar to checkout\n",
    "        history      Show repository access history\n",
    "        import       Import sources into CVS, using vendor branches\n",
    "        init         Create a CVS repository if it doesn't exist\n",
    NULL,
};
static const char *const usg[] =
{
    /* CVS usage messages never have followed the GNU convention of
       putting metavariables in uppercase.  I don't know whether that
       is a good convention or not, but if it changes it would have to
       change in all the usage messages.  For now, they consistently
       use lowercase, as far as I know.  Punctuation is pretty funky,
       though.  Sometimes they use none, as here.  Sometimes they use
       single quotes (not the TeX-ish `' stuff), as in --help-options.
       Sometimes they use double quotes, as in cvs -H add.

       Most (not all) of the usage messages seem to have periods at
       the end of each line.  I haven't tried to duplicate this style
       in --help as it is a rather different format from the rest.  */

    "Usage: %s [cvs-options] command [command-options-and-arguments]\n",
    "  where cvs-options are -q, -n, etc.\n",
    "    (specify --help-options for a list of options)\n",
    "  where command is add, admin, etc.\n",
    "    (specify --help-commands for a list of commands\n",
    "     or --help-synonyms for a list of command synonyms)\n",
    "  where command-options-and-arguments depend on the specific command\n",
    "    (specify -H followed by a command name for command-specific help)\n",
    "  Specify --help to receive this message\n",
    "\n",

    /* Some people think that a bug-reporting address should go here.  IMHO,
       the web sites are better because anything else is very likely to go
       obsolete in the years between a release and when someone might be
       reading this help.  Besides, we could never adequately discuss
       bug reporting in a concise enough way to put in a help message.  */

    /* I was going to put this at the top, but usage() wants the %s to
       be in the first line.  */
    "The Concurrent Versions System (CVS) is a tool for version control.\n",
    /* I really don't think I want to try to define "version control"
       in one line.  I'm not sure one can get more concise than the
       paragraph in ../cvs.spec without assuming the reader knows what
       version control means.  */

    "For CVS updates and additional information, see\n",
    "    the CVS home page at http://www.cvshome.org/ or\n",
    "    Pascal Molli's CVS site at http://www.loria.fr/~molli/cvs-index.html\n",
    NULL,
};
int main(int argc, char* argv[])
{
    program_name = last_component (argv[0]);
    cvs_cmd_name = argv[0];
    usage(usg);
    return 0;
}
