/****************************************************************************
 *
 * Copyright (C) 2001 ~ 2021
 * 
 *  Neutrino International Inc.
 *  Oriphase Space Travelling Industry
 *
 * Author   : Brian Lin ( Foxman , Vladimir Lin , Vladimir Forest )
 * E-mail   : lin.foxman@gmail.com
 *          : lin.vladimir@gmail.com
 *          : wolfram_lin@yahoo.com
 *          : wolfram_lin@sina.com
 *          : wolfram_lin@163.com
 * Skype    : wolfram_lin
 * WeChat   : 153-0271-7160
 * WhatsApp : 153-0271-7160
 * QQ       : lin.vladimir@gmail.com (2107437784)
 * LINE     : lin-foxman
 *
 ****************************************************************************/
//////////////////////////////////////////////////////////////////////////////
#include "qttransformers.h"
//////////////////////////////////////////////////////////////////////////////
QT_BEGIN_NAMESPACE
//////////////////////////////////////////////////////////////////////////////
void RegisterTransformers           ( void                                 ) {
  qRegisterMetaType<QtTransformers> ( "QtTransformers"                     ) ;
}
//////////////////////////////////////////////////////////////////////////////
QtTransformers:: QtTransformers ( void )                                     {
}
//////////////////////////////////////////////////////////////////////////////
QtTransformers:: QtTransformers ( const QtTransformers & manager )           {
  Transformers = manager . Transformers                                      ;
}
//////////////////////////////////////////////////////////////////////////////
QtTransformers::~QtTransformers ( void )                                     {
}
//////////////////////////////////////////////////////////////////////////////
void QtTransformers::addDefaults ( void )                                    {
}
//////////////////////////////////////////////////////////////////////////////
int QtTransformers::add ( SUID type , GenericTransformer transformer )       {
  Transformers [ type ] = transformer                                        ;
  return Transformers . count ( )                                            ;
}
//////////////////////////////////////////////////////////////////////////////
QVariantList QtTransformers::Transformer                                     (
               QVariantList     & Paraments                                  ,
               const QByteArray & Source                                     ,
                     QByteArray & Target                                   ) {
  ////////////////////////////////////////////////////////////////////////////
  QVariantList Empty                                                         ;
  ////////////////////////////////////////////////////////////////////////////
  if (   Paraments.count() <=0                             ) return Empty    ;
  if ( ! Paraments.first().canConvert<SUID>()) return Empty                  ;
  SUID type = (SUID) Paraments . first ( ) . toULongLong ( )                 ;
  if ( ! Transformers . contains ( type )                  ) return Empty    ;
  ////////////////////////////////////////////////////////////////////////////
  return Transformers [ type ] ( Paraments , Source , Target )               ;
}
//////////////////////////////////////////////////////////////////////////////
QT_END_NAMESPACE
//////////////////////////////////////////////////////////////////////////////
