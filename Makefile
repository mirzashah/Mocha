# Makefile for Mocha

CC = g++
CFLAGS = -O0 -g -I. -c -DLINUX -DILUT_USE_OPENGL -I$(HELPERPROJECTS)/MapSystemCore -I$(HELPERPROJECTS)/MaSUtilities \
		$(shell pkg-config --cflags  ftgl) \
		$(shell pkg-config --cflags  gtkmm-2.4) \
		$(shell pkg-config --cflags  gtkglext-1.0)
		
OUT = ../Debug/libMocha.a

OBJS =	BoundAreaNode.o \
		Circle.o \
		Color.o \
		ContainerHelper.o \
		DevicePoint.o \
		DOFNode.o \
		DOMNode.o \
		Drawable.o \
		Drawing.o \
		EventInterface.o \
		EventRegister.o \
		EventVisitor.o \
		FontCache.o \
		Font.o \
		FunButton.o \
		FunNode.o \
		GeoNode.o \
		GraphVisitor.o \
		Image.o \
		ImageLoader.o \
		MapSystemNode.o \
		Mocha.o \
		MochaException.o \
		MochaObject.o \
		Point.o \
		ProjectionNode.o \
		RectangleBoundAreaNode.o \
		Rectangle.o \
		RenderVisitor.o \
		RotateNode.o \
		ScaleNode.o \
		SceneManager.o \
		SceneNode.o \
		Shape.o \
		TranslateNode.o

all:	createLibrary

createLibrary:	$(OBJS)
		ar rcs $(OUT) $(OBJS) 
.cpp.o:
	$(CC) $(CFLAGS) -o $*.o $*.cpp

clean:
	rm -f $(OBJS) $(OUT) *~
