/****************************************************************************
 *
 * Copyright (C) 2015 Neutrino International Inc.
 *
 * Author   : Brian Lin ( Vladimir Lin , Vladimir Forest )
 * E-mail   : lin.foxman@gmail.com
 *          : lin.vladimir@gmail.com
 *          : wolfram_lin@yahoo.com
 *          : wolfram_lin@sina.com
 *          : wolfram_lin@163.com
 * Skype    : wolfram_lin
 * WeChat   : 153-0271-7160
 * WhatsApp : 153-0271-7160
 * QQ       : lin.vladimir@gmail.com
 * URL      : http://qtlzo.sourceforge.net/
 *
 * QtTAR acts as an interface between Qt and GNU TAR library.
 * Please keep QtTAR as simple as possible.
 *
 * Copyright 2001 ~ 2015
 *
 ****************************************************************************/

#ifndef QT_TRANSFORMERS_H
#define QT_TRANSFORMERS_H

#include <QtCore>
#include <QtUUID>

QT_BEGIN_NAMESPACE

#ifndef QT_STATIC
#    if defined(QT_BUILD_QTTRANSFORMERS_LIB)
#      define Q_TRANSFORMERS_EXPORT Q_DECL_EXPORT
#    else
#      define Q_TRANSFORMERS_EXPORT Q_DECL_IMPORT
#    endif
#else
#      define Q_TRANSFORMERS_EXPORT
#endif

#define QT_TRANSFORMERS_LIB 1

#define TransformerParameters   QVariantList     & Paraments , \
                                const QByteArray & Source    , \
                                      QByteArray & Target
#define TransformerDefine(func) QVariantList func(DeclTransformer)

typedef QVariantList (* GenericTransformer ) (TransformerParameters) ;

class Q_TRANSFORMERS_EXPORT QtTransformers
{
  public:

    explicit     QtTransformers (void) ;
                 QtTransformers (const QtTransformers & manager) ;
    virtual     ~QtTransformers (void) ;

    int          add            (SUID               type          ,
                                 GenericTransformer transformer ) ;
    QVariantList Transformer    (TransformerParameters) ;

    virtual void addDefaults    (void) ;

  protected:

    QMap<SUID,GenericTransformer> Transformers ;

  private:

} ;

Q_TRANSFORMERS_EXPORT void RegisterTransformers(void) ;

Q_DECLARE_METATYPE(QtTransformers)

QT_END_NAMESPACE

#endif
