#include <QtCore/QCoreApplication>
#include <../algorithms/anyoption.h>
#include <../algorithms/nameconverter.h>

void readoption(int argc, char *argv[], bool *convertDir,
                QString *filename, QString *dir, QString *path);

int main(int argc, char *argv[])
{
    bool convertDir = false;
    NameConverter nc;
    QString filename;
    QString dir;
    QString path;
    readoption(argc, argv, &convertDir, &filename, &dir, &path);
    if (convertDir == false) {
        if (nc.convertFile(filename, path) == true) {
        }
        else {
            qDebug() << "fail to convert the file \"" << filename << "\"";
        }
    }
    else {
        nc.convertDir(dir, path);
    }
    return 0;
}


void readoption(int argc, char *argv[], bool *convertDir,
                QString *filename, QString *dir, QString *path)
{
    /* 1. CREATE AN OBJECT */
    AnyOption *opt = new AnyOption();

    /* 2. SET PREFERENCES  */
    //opt->noPOSIX(); /* do not check for POSIX style character options */
    //opt->setVerbose(); /* print warnings about unknown options */
    //opt->autoUsagePrint(true); /* print usage for bad options */

    /* 3. SET THE USAGE/HELP   */
    opt->addUsage( "" );
    opt->addUsage( "Usage: " );
    opt->addUsage( "" );
    opt->addUsage( " -h  --help               Prints this help " );
    opt->addUsage( " -f  --filename FILENAME  Filename to be converted " );
    opt->addUsage( " -d  --dir DIRECTORY      File dir to be converted " );
    opt->addUsage( " -p  --path PATH          Path where converted file saves " );
    opt->addUsage( "" );

    /* 4. SET THE OPTION STRINGS/CHARACTERS */

    /* by default all  options  will be checked on the command line and from option/resource file */
    opt->setFlag(  "help", 'h' );   /* a flag (takes no argument), supporting long and short form */
    opt->setOption(  "filename", 'f' ); /* an option (takes an argument), supporting long and short form */
    opt->setOption(  "dir", 'd' ); /* an option (takes an argument), supporting long and short form */
    opt->setOption(  "path", 'p' ); /* an option (takes an argument), supporting long and short form */

    /* 5. PROCESS THE COMMANDLINE AND RESOURCE FILE */

    /* go through the command line and get the options  */
    opt->processCommandArgs( argc, argv );

    if( ! opt->hasOptions()) { /* print usage if no options */
        opt->printUsage();
        delete opt;
        return;
    }

    /* 6. GET THE VALUES */
    if( opt->getFlag( "help" ) || opt->getFlag( 'h' ) )
        opt->printUsage();
    if( opt->getValue( 'f' ) != NULL  || opt->getValue( "filename" ) != NULL  ) {
        *convertDir = false;
        filename->append(QString(opt->getValue( 'f' )));
    }
    if( opt->getValue( 'd' ) != NULL  || opt->getValue( "dir" ) != NULL  ) {
        *convertDir = true;
        dir->append(QString(opt->getValue( 'd' )));
    }
    if( opt->getValue( 'p' ) != NULL  || opt->getValue( "path" ) != NULL  ) {
        path->append(QString(opt->getValue( 'p' )));
    }

    /* 8. DONE */
    delete opt;
}
