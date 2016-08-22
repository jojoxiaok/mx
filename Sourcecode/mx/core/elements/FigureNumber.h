// MusicXML Class Library v0.3.0
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#pragma once

#include "mx/core/ForwardDeclare.h"
#include "mx/core/ElementInterface.h"
#include "mx/core/Strings.h"
#include "mx/core/elements/FigureNumberAttributes.h"

#include <iosfwd>
#include <memory>
#include <vector>

namespace mx
{
    namespace core
    {

        MX_FORWARD_DECLARE_ATTRIBUTES( FigureNumberAttributes )
        MX_FORWARD_DECLARE_ELEMENT( FigureNumber )

        inline FigureNumberPtr makeFigureNumber() { return std::make_shared<FigureNumber>(); }
		inline FigureNumberPtr makeFigureNumber( const XsString& value ) { return std::make_shared<FigureNumber>( value ); }
		inline FigureNumberPtr makeFigureNumber( XsString&& value ) { return std::make_shared<FigureNumber>( std::move( value ) ); }

        class FigureNumber : public ElementInterface
        {
        public:
            FigureNumber();
            FigureNumber( const XsString& value );

            virtual bool hasAttributes() const;
            virtual bool hasContents() const;
            virtual std::ostream& streamAttributes( std::ostream& os ) const;
            virtual std::ostream& streamName( std::ostream& os ) const;
            virtual std::ostream& streamContents( std::ostream& os, const int indentLevel, bool& isOneLineOnly ) const;
            FigureNumberAttributesPtr getAttributes() const;
            void setAttributes( const FigureNumberAttributesPtr& attributes );
            XsString getValue() const;
            void setValue( const XsString& value );

            bool fromXElement( std::ostream& message, xml::XElement& xelement );

        private:
            XsString myValue;
            FigureNumberAttributesPtr myAttributes;
        };
    }
}
