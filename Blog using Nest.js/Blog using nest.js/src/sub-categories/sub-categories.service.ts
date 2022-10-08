import { Injectable } from '@nestjs/common';
import { PrismaService } from 'src/prisma/prisma.service';
import { CreateSubCategoryDto } from './dto/create-sub-category.dto';
import { UpdateSubCategoryDto } from './dto/update-sub-category.dto';

@Injectable()
export class SubCategoriesService {
  constructor(private prismaService: PrismaService) {}
  create(createSubCategoryDto: CreateSubCategoryDto) {
    return this.prismaService.subcategory.create({
      data: createSubCategoryDto,
    });
  }

  findAll() {
    return this.prismaService.subcategory.findMany();
  }

  findOne(id: string) {
    return this.prismaService.subcategory.findFirst({
      where: {
        id: id,
      },
    });
  }

  update(id: string, updateSubCategoryDto: UpdateSubCategoryDto) {
    return this.prismaService.subcategory.update({
      data: updateSubCategoryDto,
      where: { id: id },
    });
  }

  remove(id: string) {
    return this.prismaService.subcategory.delete({
      where: {
        id: id,
      },
    });
  }

  getSubCategories(categoryId: string) {
    return this.prismaService.subcategory.findMany({
      where: {
        categoryId: categoryId,
      },
    });
  }
}
